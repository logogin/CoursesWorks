DECLARE 
   x delme.a%TYPE;
   y delme.b%TYPE;
CURSOR MyCursor is 
SELECT a,b FROM delme WHERE a<=b FOR UPDATE;
BEGIN
    OPEN  MyCursor;
    LOOP
       FETCH MyCursor INTO x,y;
       EXIT WHEN MyCursor%NOTFOUND;
       DELETE FROM delme WHERE CURRENT OF  MyCursor;
       INSERT INTO delme VALUES(y,x+2);
    END LOOP;
    CLOSE  MyCursor;
END;
.
RUN;