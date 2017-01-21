/*
** This block finds the first employee who has a salary over $4000
** and is higher in the chain of command than employee 7902.
*/

DECLARE
    salary          emp.sal%TYPE;
    mgr_num         emp.mgr%TYPE;
    last_name       emp.ename%TYPE;
    starting_empno  CONSTANT NUMBER(4) := 7902;
BEGIN
    SELECT sal, mgr INTO salary, mgr_num FROM emp
        WHERE empno = starting_empno;
    WHILE salary < 4000 LOOP
        SELECT sal, mgr, ename INTO salary, mgr_num, last_name
            FROM emp
            WHERE empno = mgr_num;
    END LOOP;

    INSERT INTO temp VALUES (NULL, salary, last_name);
    COMMIT;
END;
/
