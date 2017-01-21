CREATE OR REPLACE Procedure Incr_Sal(empno NUMBER,sal_inc NUMBER)
IS
curr_sal NUMBER(7,2);
BEGIN
SELECT sal INTO curr_sal FROM emp WHERE emp.empno=Incr_Sal.empno;
IF curr_sal IS NOT NULL THEN 
UPDATE emp SET sal=sal+sal_inc
WHERE empno=empno;
END IF;
END;
.
run;
/* to execute :
begin Incr_Sal(7839,100);
end;
.
run;
*/
