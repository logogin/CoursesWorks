/*  --------------------------------file progr1.sql -----------------*/
CREATE OR REPLACE PROCEDURE findDel
(in_empid IN NUMBER ,return_code OUT NUMBER)   AS
counter NUMBER;
BEGIN
SELECT COUNT(*) INTO counter
      FROM emp;
IF counter=0 THEN
      return_code:=2;
ELSE
    SELECT COUNT(*) INTO counter    FROM emp WHERE empno=in_empid;
    IF counter=0 THEN
        return_code:=3;
    ELSE
       DELETE FROM emp      WHERE empno=in_empid;
       return_code:=4;
    END IF;
END IF;
END;
/
/*  to end  :  /   or :   .
                                  RUN;*/
/* ------------------------------------------------------*/
/*  to build procedure :      START progr1.sql;     or   @progr1.sql;   */
/* to execute :
 DECLARE 
      my_code NUMBER;
 BEGIN
       finddel(2000,my_code);
       INSERT INTO test_result VALUES(my_code);
       COMMIT;
 END;
 /
SELECT * FROM test_result;
*/
