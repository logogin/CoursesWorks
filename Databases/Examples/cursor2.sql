DECLARE
    CURSOR c1 is
	SELECT ename, empno, sal FROM emp
	ORDER BY sal DESC;   -- start with highest-paid employee
    my_ename  CHAR(10);
    my_empno  NUMBER(4);
    my_sal    NUMBER(7,2);

BEGIN
    OPEN c1;
    LOOP
	FETCH c1 INTO my_ename, my_empno, my_sal;
	EXIT WHEN (c1%ROWCOUNT > 5) OR (c1%NOTFOUND);
	INSERT INTO temp VALUES (my_sal, my_empno, my_ename);
        COMMIT;
    END LOOP;
    CLOSE c1;
END;
/
