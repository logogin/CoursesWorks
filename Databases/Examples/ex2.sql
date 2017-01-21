DECLARE
     x NUMBER(2);
     y NUMBER(2);
BEGIN
    SELECT a,b INTO x,y FROM delme WHERE  a>2;
    IF y=1 THEN
        INSERT INTO delme VALUES(y,x);
    ELSE
       INSERT INTO delme VALUES(y+10,x+10);
    END IF;
END;
. 
RUN;