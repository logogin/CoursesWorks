CREATE FUNCTION get_sal(par IN NUMBER)
RETURN NUMBER IS
var NUMBER;
BEGIN
SELECT sal INTO var FROM emp WHERE empno=par;
RETURN (var);
END;
.
run;