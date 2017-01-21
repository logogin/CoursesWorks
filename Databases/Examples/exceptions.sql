/*
** This block calculates the ratio between the X and Y columns of
** the RATIO table.  If the ratio is greater than 0.72, the block
** inserts the ratio into RESULT_TABLE.  Otherwise, it inserts -1.
** If the denominator is zero, ZERO_DIVIDE is raised, and a
** zero is inserted into RESULT_TABLE.
*/

DECLARE
    numerator    NUMBER;
    denominator  NUMBER;
    the_ratio    NUMBER;
    lower_limit  CONSTANT NUMBER := 0.72;
    samp_num     CONSTANT NUMBER := 132;
BEGIN
    SELECT x, y INTO numerator, denominator FROM result_table
        WHERE sample_id = samp_num;
    the_ratio := numerator/denominator;
    IF the_ratio > lower_limit THEN
        INSERT INTO ratio VALUES (samp_num, the_ratio);
    ELSE
        INSERT INTO ratio VALUES (samp_num, -1);
    END IF;
    COMMIT;
EXCEPTION
    WHEN ZERO_DIVIDE THEN
        INSERT INTO ratio VALUES (samp_num, 0);
        COMMIT;
    WHEN OTHERS THEN
        ROLLBACK;
END;
/
