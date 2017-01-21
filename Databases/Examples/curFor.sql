/* for with cursor  - c1_rec */
 DECLARE
 sal_new mytemp.col1%TYPE;
 CURSOR c1 IS SELECT deptno,sal FROM emp WHERE job='MANAGER';
 BEGIN
       FOR  c1_rec  IN  c1  LOOP
             IF c1_rec.sal>1500 THEN
                 sal_new:=c1_rec.sal*1.2;
                 INSERT  INTO  mytemp  VALUES(sal_new);
             END IF;
      END LOOP;

 END;
. 
run;
