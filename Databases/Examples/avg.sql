DECLARE 
x sotri.a%TYPE;
y sotri.b%TYPE;
avgx NUMBER;
avgy NUMBER;
counter NUMBER;
CURSOR MyCursor is SELECT a,b FROM sotri WHERE a>20 FOR UPDATE;
CURSOR cur2 is SELECT var1,var2 FROM temp FOR UPDATE;
BEGIN
   OPEN  MyCursor;
   OPEN cur2; 
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
INSERT INTO sotri values(avgx,avgy);
FETCH cur2 INTO x,y;
INSERT INTO temp VALUES(avgx,avgy) ;
CLOSE  MyCursor;
CLOSE cur2;
END;
.
run;
