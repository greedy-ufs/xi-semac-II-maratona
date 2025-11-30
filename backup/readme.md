Para ver os ids de blobs, faça 

````sql
SELECT
    runnumber,
    usernumber,
    runproblem,
    runfilename,
    rundata as sourceoid
  FROM runtable
  WHERE contestnumber = 1
  LIMIT 10;
```

Para ver o código da submissão faça a query 

```sql
SELECT convert_from(lo_get(16705), 'UTF8');
```
