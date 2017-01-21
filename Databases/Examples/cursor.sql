DECLARE
    CURSOR my_cursor IS SELECT sal + NVL(comm, 0) wages, ename 
        FROM emp;
    my_rec  my_cursor%ROWTYPE;
BEGIN
    OPEN my_cursor;
    LOOP
        FETCH my_cursor INTO my_rec;
        EXIT WHEN my_cursor%NOTFOUND;
        IF my_rec.wages > 2000 THEN
            INSERT INTO temp VALUES (NULL, my_rec.wages,
                my_rec.ename);
        END IF;
    END LOOP;
    CLOSE my_cursor;
END;
/
