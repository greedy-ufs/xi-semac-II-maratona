# II Maratona de Programação - SEMAC

- [Boca docker](https://github.com/joaofazolo/boca-docker)
- [Boca cheatsheet](https://github.com/gabrielrbernardi/BOCADocumentation)
- [Boca placar](https://github.com/wuerges/maratona-animeitor-rust/)
- [Caderno de problemas](https://docs.google.com/document/d/1gvnBEyPKjA8JPNlUSRVkY3Bu0ruurBE6PxNpCtgwNQc/edit?tab=t.0)

## Como criar o contest

### Máquina 1
No caso foi utilizado dois droplets do DigitalOcean

Instalar o boca

```bash
sudo apt-get update # Updating packages
sudo add-apt-repository ppa:icpc-latam/maratona-linux # Adding the official package of BOCA
sudo apt-get update # Updating packages, again
sudo apt-get install boca -y # Installing BOCA
boca-createjail
echo "allUsers 1/1/1000" > /var/www/boca/src/private/webcast.sep
```

Finalizar a configuração do apache2

```bash
sudo tee /etc/apache2/sites-available/000-boca.conf > /dev/null <<EOF
<Directory "/var/www/boca/src">
    AllowOverride Options AuthConfig Limit
    Require all granted
    AddDefaultCharset utf-8
</Directory>

<Directory "/var/www/boca/src/private">
    Require all denied
</Directory>

<Directory "/var/www/boca">
    Require all denied
</Directory>

Alias /boca /var/www/boca/src

<Files "webcast.php">
    Require all granted
</Files>
EOF

```

### Máquina 2
```bash
sudo apt-get update
sudo apt-get install ca-certificates curl
sudo install -m 0755 -d /etc/apt/keyrings
sudo curl -fsSL https://download.docker.com/linux/ubuntu/gpg -o /etc/apt/keyrings/docker.asc
sudo chmod a+r /etc/apt/keyrings/docker.asc
echo \
    "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.asc] https://download.docker.com/linux/ubuntu \
    $(. /etc/os-release && echo "$VERSION_CODENAME") stable" | \
    sudo tee /etc/apt/sources.list.d/docker.list > /dev/null

sudo apt-get update

sudo apt install docker-ce
sudo systemctl status docker

sudo apt-get update
git clone https://github.com/wuerges/maratona-animeitor-rust
cd maratona-animeitor-rust
```

```env
# Path to the file that contains the secrets used as credentials for the Reveleitor.
# There are many examples in the ./config/ folder
SECRET=./config/basic_secret.toml

# Path to the file that describes the contest locations.
# There are many examples in the ./config/ folder
SEDES=./config/basic.toml

# Boca URL that will be pooled to get the contest state.
# It can be either a file or an URL.
BOCA_URL=http://{IP_COMPUTADOR1}/boca/admin/report/webcast.php?webcastcode=allUsers

# Animeitor API prefix. This is set to `http://animeitor.naquadah.com.br` during the maratona.
# `http://localhost:8000` is fine for local testing:
PREFIX=http://localhost:8000

# This is the public port. This is set to `80` during the SBC Maratona.
# `8000` is fine for local testing:
PUBLIC_PORT=80

```
