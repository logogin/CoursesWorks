CREATE TRIGGER PersonCheckAge 
AFTER INSERT OR UPDATE OF sal ON emp
FOR EACH ROW 
BEGIN 
    IF (:new.sal < 0) THEN 
        RAISE_APPLICATION_ERROR(-20000, 'no negative age allowed'); 
    END IF; 
END; 
. 
RUN; 
