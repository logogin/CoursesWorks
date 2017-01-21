DROP TABLE newPrice;
CREATE TABLE newPrice (name VARCHAR2(30), address VARCHAR2(40), model VARCHAR2(20), price NUMBER(9,2));
DECLARE
    name Stock.sname%TYPE;
    address Stock.saddress%TYPE;
    model Stock.imodel%TYPE;
    price Stock.price%TYPE;
    CURSOR c(company VARCHAR) IS 
        SELECT sname, saddress, imodel, price FROM Stock
        WHERE icompany = company;
BEGIN
    OPEN c('Opel');
        LOOP
            FETCH c INTO name, address, model, price;
            EXIT WHEN c%NOTFOUND;
            price := price + price * 0.1;
            INSERT INTO newPrice VALUES (name, address, model, price);
        END LOOP;
    CLOSE c;
END;
