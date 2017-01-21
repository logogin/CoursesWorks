/*drop table sal_guide;
create table sal_guide( minsal NUMBER(7,2),maxsal NUMBER(7,2),job VARCHAR2(9));
 insert into  sal_guide values(2000,8000,'MANAGER');
 insert into  sal_guide values(5000,10000,'PRESIDENT');
 insert into sal_guide values(1000,3000,'SALESMAN');
 insert into sal_guide values(1000,3000,'CLERK');
 insert into sal_guide values(3000,5000,'ANALYST');*/

CREATE OR REPLACE TRIGGER CheckSal
BEFORE 
INSERT OR UPDATE OF sal,job ON emp 
FOR EACH ROW
WHEN (NEW.job<>'MANAGER')
DECLARE
minsal NUMBER;
maxsal NUMBER;
BEGIN
 SELECT minsal,maxsal INTO minsal,maxsal FROm sal_guide
WHERE job=:NEW.job;
IF(:NEW.sal<minsal OR :NEW.sal>maxsal) THEN
         raise_application_error(-20601,'Value of sal ' || :NEW.sal|| 'NOT inside range '||
 :NEW.job || ' for employee '||:NEW.ename);
   END IF;
END CheckSal;
.
RUN;
show errors;
