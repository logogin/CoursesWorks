/*
DROP TABLE Vip;
CREATE TABLE Vip (name VARCHAR2(30) , address VARCHAR2(40) , payment NUMBER(10) , status VARCHAR2(4) DEFAULT NULL); 
INSERT INTO Vip (name , address , payment)
(SELECT name, address, SUM(money) money FROM
                (SELECT name, address, (price * quantity) money FROM Stock,
                        (SELECT stname, staddress, stmodel, stcompany, name, address, quantity FROM Quantities,
                                (SELECT id, cname name, caddress address FROM Orders, CreditCards
                                 WHERE Orders.ccnum = CreditCards.num)
                         WHERE id = oid)
                WHERE sname = stname AND saddress = staddress AND imodel = stmodel AND icompany = stcompany)
         GROUP BY name, address);
SELECT * FROM Vip;

DECLARE
      pay_of  NUMBER(10);
      maximum CONSTANT NUMBER(7) := 1000000;
      CURSOR c1 IS SELECT payment FROM Vip; 
BEGIN
     OPEN c1;
     LOOP
     FETCH c1 INTO pay_of;
      EXIT WHEN c1%NOTFOUND;
      IF pay_of >= maximum     THEN
       UPDATE Vip SET status = 'YES' WHERE payment = pay_of;
      ELSE UPDATE Vip SET status = 'NOT' WHERE payment = pay_of;
     END IF;
     END LOOP;
     CLOSE c1;
END;             
 */
SELECT * FROM Vip;