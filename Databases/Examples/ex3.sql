DECLARE
     i NUMBER(2):=2;
BEGIN
   LOOP
            INSERT INTO  delme VALUES(i,i);
            i:=i+1;
            EXIT WHEN i>10;
   END LOOP;
END;
.
RUN;