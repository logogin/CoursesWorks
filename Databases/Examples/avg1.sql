/* Program calculate average value */
DECLARE 
x example.a%TYPE;
y example.b%TYPE;
avgx NUMBER;
avgy NUMBER;
counter NUMBER;
CURSOR MyCursor is SELECT a,b FROM example WHERE a>20 FOR UPDATE;
CURSOR CurTemp is SELECT var1,var2 FROM temp FOR UPDATE;
BEGIN
   OPEN  MyCursor;
   OPEN CurTemp; 
avgx:=0;
avgy:=0;
counter:=0;
LOOP
      FETCH MyCursor INTO x,y;
       avgx:=avgx+x;
       avgy:=avgy+y;
       counter:=counter+1;
      EXIT WHEN MyCursor%NOTFOUND;
END LOOP;
avgx:=avgx/counter;
avgy:=avgy/counter;
INSERT INTO example values(avgx,avgy);
FETCH CurTemp INTO x,y;
INSERT INTO temp VALUES(avgx,avgy) ;
CLOSE  MyCursor;
CLOSE CurTemp;
END;
.
run;
