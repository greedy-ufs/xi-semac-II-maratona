from pathlib import Path

FOLDER_PATH = Path(__file__).parent / "B/output"

for file_path in FOLDER_PATH.iterdir():
    if file_path.is_file():
        file_stem = file_path.stem
        new_name = f"B_{file_stem}"  # no extension
        new_path = file_path.parent / new_name
        counter = 1
        while new_path.exists():
            new_path = file_path.parent / f"{new_name}_{counter}"
            counter += 1
        file_path.rename(new_path)
        print(f"Renamed: {file_path.name} -> {new_path.name}")