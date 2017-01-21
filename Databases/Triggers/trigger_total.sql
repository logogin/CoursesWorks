set serverout on;
drop table empl;
drop table empsalary;
drop table depart;
create table empl(id number(4),name varchar2(15),deptno number(3));
create table empsalary(id_emp number(4),salary number(7,2));
create table depart (deptno number(3),dname varchar2(10),totalemp number(6));
DROP TRIGGER OutTrigger;
CREATE TRIGGER OutTrigger
BEFORE  INSERT ON empl 
FOR EACH ROW
DECLARE
counter NUMBER(2);
BEGIN
     SELECT COUNT(*) INTO counter FROM empl WHERE id=(:NEW.id);
     IF counter<>0 THEN
         raise_application_error(-20502,' ID of employee exist ');
     ELSE 
         INSERT INTO empsalary(id_emp) VALUES(:NEW.id);
        SELECT COUNT(*) INTO counter FROM depart WHERE depart.deptno=(:NEW.deptno);
       dbms_output.put_line(' counter= '||counter || 'DEptno= '|| (:NEW.deptno));
        IF counter=0 THEN 
            INSERT INTO  depart(deptno,totalemp)  VALUES(:NEW.deptno,1);
        ELSE
            UPDATE depart SET totalemp=totalemp+1 WHERE depart.deptno=(:NEW.deptno);
        END IF;
     END IF;
     END OutTrigger;
.
RUN;
show errors;
