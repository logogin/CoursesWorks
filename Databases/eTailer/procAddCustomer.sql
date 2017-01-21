DECLARE
FUNCTION IsCustomerExist(cname VARCHAR2 , caddress VARCHAR2) RETURN BOOLEAN IS
   n NUMBER(3);
BEGIN
        SELECT COUNT(*) INTO n FROM Customers WHERE name = cname AND address = caddress GROUP BY (name);   
 IF n > 0  THEN RETURN TRUE;
    ELSE RETURN FALSE;
    END IF;
END IsCustomerExist;

FUNCTION IsCreditCardExist(ccnum VARCHAR2)  RETURN BOOLEAN IS
    n NUMBER(3);
BEGIN
   SELECT COUNT(num) INTO n FROM CreditCards WHERE num = ccnum ;   
IF n > 0  THEN RETURN TRUE;
    ELSE RETURN FALSE;   
    END IF; 
END IsCreditCardExist;

PROCEDURE AddCustomer(cname VARCHAR2 , caddress VARCHAR2  , cemail VARCHAR2 ,ccnum VARCHAR2 , cccompany VARCHAR2 , ccdate DATE ) IS
BEGIN 
    IF IsCreditCardExist(ccnum) THEN raise_application_error(-20330 , 'ERROR: THE CARD ALREADY EXIST');
    ELSE
        IF NOT IsCustomerExist(cname, caddress) THEN 
            INSERT INTO Customers VALUES(cname , caddress , cemail) ;      
        END IF;       
    INSERT INTO CreditCards VALUES(ccnum , cccompany , ccdate , cname , caddress);  
    END IF;
END AddCustomer;

BEGIN
    AddCustomer('Ivanov Ivan','Russia,  Moskva ,Petrovka 38','ivan@mail.ru','1111 0000 0000 0004','Master Card',to_date('10/2005','mm/yyyy'));
END;
