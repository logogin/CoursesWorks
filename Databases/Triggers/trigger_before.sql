CREATE OR REPLACE TRIGGER emp_trigger
BEFORE 
DELETE OR INSERT OR UPDATE  ON emp 
BEGIN
IF (TO_CHAR(SYSDATE,'DY')='SAT')  THEN 
       raise_application_error(-20501,' Invalid date for work ');
END IF;
IF (TO_CHAR(SYSDATE,'HH24')< 8 
OR TO_CHAR(SYSDATE,'HH24') >= 18)  THEN 
       raise_application_error(-20502,' Invalid time for work');
END IF;
END emp_trigger;
.
RUN;
show errors;
