DROP TABLE MinimalPrice;
CREATE TABLE MinimalPrice(sname VARCHAR2(30) , saddress VARCHAR2(40) , model VARCHAR2(20) , company VARCHAR2(20) , price NUMBER(7));
DECLARE 
     model_i  Items.model%TYPE;
     company_i Items.company%TYPE;
     s_name Suppliers.name%TYPE;
     s_address Suppliers.address%TYPE;
     price_ Stock.price%TYPe;
     CURSOR cItem IS SELECT model , company FROM Items;
     CURSOR cStock(model Items.model%TYPE , company Items.company%TYPE) IS SELECT sname , saddress , imodel , icompany , price
             FROM Stock WHERE imodel = model AND icompany = company ORDER BY price;
BEGIN 
     OPEN cItem;
<<A2>>FETCH cItem INTO model_i , company_i;
            IF cItem%NOTFOUND THEN GOTO A1;
            ELSE
                OPEN cStock(model_i , company_i);
                IF cStock%NOTFOUND THEN raise_application_error(-20001,'ERROR: ITEM NOT FOUND!');
                ELSE
                   FETCH cStock  INTO s_name , s_address , model_i , company_i , price_ ;
                   INSERT INTO MinimalPrice VALUES(s_name , s_address , model_i , company_i , price_);
                END IF;
                CLOSE cStock;
                GOTO A2;
             END IF;
<<A1>> 
NULL;
END;
