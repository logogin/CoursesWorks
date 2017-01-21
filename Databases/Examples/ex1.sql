CREATE TABLE delme(a NUMBER(2),b NUMBER(2));
DELETE FROM delme;
INSERT INTO delme VALUES(1,3);
INSERT INTO delme VALUES(2,4);
DECLARE
   x NUMBER(2);
   y NUMBER(2);
BEGIN
    SELECT a,b INTO x,y FROM delme WHERE a>1;
    INSERT INTO delme VALUES(y,x);
END;
.
RUN;
