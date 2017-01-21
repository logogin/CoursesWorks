DROP TABLE tAvaregePricePerType;
CREATE TABLE tAvaregePricePerType (type VARCHAR2(20), price NUMBER(9,2));
DECLARE
    type_i Items.type%TYPE;
    price NUMBER(20);
    counter NUMBER(3);
    CURSOR cType IS SELECT DISTINCT type FROM Items;
BEGIN
    OPEN cType;
        LOOP
             FETCH cType INTO type_i;
             EXIT WHEN cType%NOTFOUND;
                 SELECT SUM(price), COUNT(price) INTO price, counter FROM Items, Stock
                 WHERE type = type_i AND model = imodel AND company = icompany;
                 INSERT INTO tAvaregePricePerType VALUES (type_i, price/counter);
        END LOOP;
    CLOSE cType;     
END;