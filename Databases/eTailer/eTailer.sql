DROP TABLE Vip;
DROP TABLE Quantities;
DROP TABLE Stock;
DROP TABLE Suppliers;
DROP TABLE Items;
DROP TABLE CreditCards;
DROP TABLE Orders;
DROP TABLE Customers;
DROP VIEW vPaysOfCustomers;
DROP VIEW vBuy_Cars;
DROP VIEW vBuyCreditCard;
DROP TABLE ItemOfUMI;
DROP TABLE CreditCardsOfBilGates;

CREATE TABLE Suppliers(name VARCHAR2(30), address VARCHAR2(40), logo VARCHAR2(20), PRIMARY KEY(name, address));
CREATE TABLE Items(model VARCHAR2(20), company VARCHAR2(20), type VARCHAR2(20), PRIMARY KEY(model, company));
CREATE TABLE Customers(name VARCHAR2(30), address VARCHAR2(30), email VARCHAR(20), PRIMARY KEY(name, address));                                        
CREATE TABLE CreditCards(num VARCHAR2(19) PRIMARY KEY, company VARCHAR2(20), expirationdate DATE, cname VARCHAR2(30), caddress VARCHAR2(30),
                                            FOREIGN KEY (cname, caddress) REFERENCES Customers(name, address));
CREATE TABLE Orders(id NUMBER(10) PRIMARY KEY, ccnum VARCHAR2(19),  FOREIGN KEY (ccnum) REFERENCES CreditCards(num));

CREATE TABLE Stock(sname VARCHAR2(30), saddress VARCHAR2(40), imodel VARCHAR2(20), icompany VARCHAR2(20),  price NUMBER(7), 
                                   PRIMARY KEY (sname, saddress, imodel, icompany),
                                   FOREIGN KEY (sname, saddress) REFERENCES Suppliers (name , address) , 
                                   FOREIGN KEY (imodel, icompany) REFERENCES Items (model, company));

CREATE TABLE Quantities(stname VARCHAR2(30), staddress VARCHAR2(40), stmodel VARCHAR2(20), stcompany VARCHAR2(20), oid NUMBER(10), quantity NUMBER(4),
                                       PRIMARY KEY (stname, staddress, stmodel, stcompany, oid),
                                       FOREIGN KEY (stname, staddress, stmodel, stcompany) REFERENCES Stock (sname, saddress, imodel, icompany),
                                       FOREIGN KEY (oid) REFERENCES Orders (id));

INSERT INTO Suppliers VALUES ('UMI Opel', 'Rishon Le Tsion, Peltin 5', 'UMI');
INSERT INTO Suppliers VALUES ('UMI Buick', 'Rishon Le Tsion, Peltin 5', 'UMI');
INSERT INTO Suppliers VALUES ('UMI Isuzu', 'Rishon Le Tsion, Peltin 5', 'UMI');
INSERT INTO Suppliers VALUES ('Chempion Audi', 'Bney Brack, Baruh Khirsh 27', 'Chempion');
INSERT INTO Suppliers VALUES ('Kolmobile Mercedes', 'Tel Aviv, Hashlosha 2', 'Kolmobile');
INSERT INTO Suppliers VALUES ('Kolmobile Hyundai', 'Tel Aviv, Igal Alon 92', 'Kolmobile');
INSERT INTO Suppliers VALUES ('M.C.I. Porshe', 'Tel Aviv, Dereh Petah Tikva 74', 'M.C.I.');
INSERT INTO Suppliers VALUES ('Delek Motors Hyundai', 'Tel Aviv, Hamlaha 3', 'Delek Motors');
INSERT INTO Suppliers VALUES ('Delek Motors Isuzu', 'Tel Aviv, Hamlaha 3', 'Delek Motors');
SELECT * FROM Suppliers;

INSERT INTO Items VALUES ('Corsa TDI', 'Opel', 'private');
INSERT INTO Items VALUES ('Astra Station', 'Opel', 'private');
INSERT INTO Items VALUES ('Omega', 'Opel', 'private');
INSERT INTO Items VALUES ('Custom', 'Buick', 'private');
INSERT INTO Items VALUES ('Trooper', 'Isuzu', 'jeep');
INSERT INTO Items VALUES ('Ippon', 'Isuzu', 'jeep');
INSERT INTO Items VALUES ('A6', 'Audi', 'private');
INSERT INTO Items VALUES ('TT', 'Audi', 'private');
INSERT INTO Items VALUES ('A8', 'Audi', 'private');
INSERT INTO Items VALUES ('Allroad', 'Audi', 'jeep');
INSERT INTO Items VALUES ('A Class', 'Mercedes', 'private');
INSERT INTO Items VALUES ('S Class', 'Mercedes', 'sport');
INSERT INTO Items VALUES ('E Class', 'Mercedes', 'private');
INSERT INTO Items VALUES ('M Class', 'Mercedes', 'jeep');
INSERT INTO Items VALUES ('Eccent', 'Hyundai', 'private');
INSERT INTO Items VALUES ('Sanata', 'Hyundai', 'private');
INSERT INTO Items VALUES ('Glooper', 'Hyundai', 'jeep');
INSERT INTO Items VALUES ('Boxter', 'Porshe', 'sport');
INSERT INTO Items VALUES ('911', 'Porshe', 'sport');
SELECT * FROM Items;

INSERT INTO Customers VALUES ('Bil Gates', 'Silicon Valey', 'bil@microsoft.com');
INSERT INTO Customers ( name, address) VALUES ('Antibiotik', 'Sant Piterburg');
INSERT INTO Customers VALUES ('Orange co.', 'Hertsiliya, Haagana 100', 'obox@orange.co.il');
INSERT INTO Customers VALUES ('Israeli tours', 'Arava', 'isratour@hotmail.com');
SELECT * FROM Customers;

INSERT INTO CreditCards VALUES ('1111 0000 0000 0001', 'Visa', to_date ('10/2004','mm/yyyy'), 'Bil Gates', 'Silicon Valey');
INSERT INTO CreditCards VALUES ('1111 0000 0000 0002', 'Visa', to_date ('05/2004','mm/yyyy'), 'Antibiotik', 'Sant Piterburg');
INSERT INTO CreditCards VALUES ('1111 0000 0000 0003', 'Visa', to_date ('11/2003','mm/yyyy'), 'Antibiotik', 'Sant Piterburg');
INSERT INTO CreditCards VALUES ('2222 0000 0000 0001', 'Isracard', to_date ('01/2005','mm/yyyy'), 'Orange co.', 'Hertsiliya, Haagana 100');
INSERT INTO CreditCards VALUES ('2222 0000 0000 0002', 'Isracard', to_date ('02/2004','mm/yyyy'), 'Israeli tours', 'Arava');
INSERT INTO CreditCards VALUES ('3333 0000 0000 0001', 'American Express', to_date ('1/2010','mm/yyyy'), 'Bil Gates', 'Silicon Valey');
SELECT * FROM CreditCards;

INSERT INTO Stock Values ('UMI Opel', 'Rishon Le Tsion, Peltin 5', 'Corsa TDI', 'Opel', 86000);
INSERT INTO Stock Values ('UMI Opel', 'Rishon Le Tsion, Peltin 5', 'Astra Station', 'Opel', 126000);
INSERT INTO Stock Values ('UMI Opel', 'Rishon Le Tsion, Peltin 5', 'Omega', 'Opel', 235000);
INSERT INTO Stock Values ('UMI Buick', 'Rishon Le Tsion, Peltin 5',  'Custom', 'Buick', 251000);
INSERT INTO Stock Values ('UMI Isuzu', 'Rishon Le Tsion, Peltin 5', 'Trooper', 'Isuzu', 210000);
INSERT INTO Stock Values ('UMI Isuzu', 'Rishon Le Tsion, Peltin 5', 'Ippon', 'Isuzu', 120000);
INSERT INTO Stock Values ('Chempion Audi', 'Bney Brack, Baruh Khirsh 27', 'A6', 'Audi', 300000);
INSERT INTO Stock Values ('Chempion Audi', 'Bney Brack, Baruh Khirsh 27', 'TT', 'Audi', 300000);
INSERT INTO Stock Values ('Chempion Audi', 'Bney Brack, Baruh Khirsh 27', 'A8', 'Audi', 600000);
INSERT INTO Stock Values ('Chempion Audi', 'Bney Brack, Baruh Khirsh 27', 'Allroad', 'Audi', 420000);
INSERT INTO Stock Values ('Kolmobile Mercedes', 'Tel Aviv, Hashlosha 2',  'A Class', 'Mercedes', 150000);
INSERT INTO Stock Values ('Kolmobile Mercedes', 'Tel Aviv, Hashlosha 2', 'E Class', 'Mercedes', 350000);
INSERT INTO Stock Values ('Kolmobile Mercedes', 'Tel Aviv, Hashlosha 2', 'S Class', 'Mercedes', 600000);
INSERT INTO Stock Values ('Kolmobile Mercedes', 'Tel Aviv, Hashlosha 2', 'M Class', 'Mercedes', 400000);
INSERT INTO Stock Values ('Kolmobile Hyundai', 'Tel Aviv, Igal Alon 92', 'Eccent', 'Hyundai', 90000);
INSERT INTO Stock Values ('Kolmobile Hyundai', 'Tel Aviv, Igal Alon 92', 'Sanata', 'Hyundai', 130000);
INSERT INTO Stock Values ('Kolmobile Hyundai', 'Tel Aviv, Igal Alon 92', 'Glooper', 'Hyundai', 150000);
INSERT INTO Stock Values ('M.C.I. Porshe', 'Tel Aviv, Dereh Petah Tikva 74', 'Boxter', 'Porshe', 450000);
INSERT INTO Stock Values ('M.C.I. Porshe', 'Tel Aviv, Dereh Petah Tikva 74', '911', 'Porshe', 1200000);
INSERT INTO Stock Values ('Delek Motors Hyundai', 'Tel Aviv, Hamlaha 3', 'Sanata', 'Hyundai', 92000);
INSERT INTO Stock Values ('Delek Motors Isuzu', 'Tel Aviv, Hamlaha 3', 'Ippon', 'Isuzu', 125000);
SELECT * FROM Stock;

INSERT INTO Orders VALUES (1000000001, '1111 0000 0000 0001');
INSERT INTO Orders VALUES (1000000002, '2222 0000 0000 0002');
INSERT INTO Orders VALUES (1000000003, '1111 0000 0000 0002');
INSERT INTO Orders VALUES (1000000004, '3333 0000 0000 0001');
INSERT INTO Orders VALUES (1000000005, '1111 0000 0000 0001');
SELECT * FROM Orders;

INSERT INTO Quantities VALUES ('Kolmobile Hyundai', 'Tel Aviv, Igal Alon 92', 'Eccent', 'Hyundai', 1000000001, 5);
INSERT INTO Quantities VALUES ('Kolmobile Mercedes', 'Tel Aviv, Hashlosha 2', 'E Class', 'Mercedes', 1000000001, 1);
INSERT INTO Quantities VALUES ('UMI Isuzu', 'Rishon Le Tsion, Peltin 5', 'Ippon', 'Isuzu', 1000000002, 2);
INSERT INTO Quantities VALUES ('UMI Isuzu', 'Rishon Le Tsion, Peltin 5', 'Trooper', 'Isuzu', 1000000002, 2);
INSERT INTO Quantities VALUES ('Kolmobile Hyundai', 'Tel Aviv, Igal Alon 92', 'Glooper', 'Hyundai', 1000000002, 2);
INSERT INTO Quantities VALUES ('Kolmobile Mercedes', 'Tel Aviv, Hashlosha 2', 'E Class', 'Mercedes', 1000000003, 5);
INSERT INTO Quantities VALUES ('Kolmobile Mercedes', 'Tel Aviv, Hashlosha 2', 'M Class', 'Mercedes', 1000000003, 5);
INSERT INTO Quantities VALUES ('Kolmobile Mercedes', 'Tel Aviv, Hashlosha 2', 'S Class', 'Mercedes', 1000000003, 1);
INSERT INTO Quantities VALUES ('Chempion Audi', 'Bney Brack, Baruh Khirsh 27', 'TT', 'Audi', 1000000004, 1);
INSERT INTO Quantities VALUES ('Chempion Audi', 'Bney Brack, Baruh Khirsh 27', 'A8', 'Audi', 1000000004, 1);
INSERT INTO Quantities VALUES ('M.C.I. Porshe', 'Tel Aviv, Dereh Petah Tikva 74', '911', 'Porshe', 1000000004, 1);
INSERT INTO Quantities VALUES ('Delek Motors Hyundai', 'Tel Aviv, Hamlaha 3', 'Sanata', 'Hyundai', 1000000005, 3);
INSERT INTO Quantities VALUES ('Kolmobile Hyundai', 'Tel Aviv, Igal Alon 92', 'Sanata', 'Hyundai', 1000000005, 3);
SELECT * FROM Quantities;
rem ==============================   SELECT   =================================================
rem 1. Amount of money that Bil Gates pay for all his orders
SELECT SUM (amount) sum FROM 
        (SELECT (price * quantity) amount FROM Stock, Quantities
         WHERE sname = stname AND saddress = staddress AND  imodel = stmodel AND icompany = stcompany AND oid IN
                (SELECT id FROM Orders
                 WHERE ccnum IN
                        (SELECT num FROM CreditCards
                         WHERE (cname, caddress) IN
                                (SELECT name, address FROM Customers
                                 WHERE name = 'Antibiotik' AND address = 'Sant Piterburg'))));

rem 2. The company and model of cars that must populary
SELECT * FROM
    (SELECT company, model, amount FROM Items, 
           (SELECT stmodel m, stcompany c, SUM(quantity) amount FROM Quantities
            GROUP BY stmodel, stcompany)
    WHERE model = m AND company = c)
WHERE amount >= ALL(SELECT amount FROM 
        (SELECT company, model, amount FROM Items, 
           (SELECT stmodel m, stcompany c, SUM(quantity) amount FROM Quantities
            GROUP BY stmodel, stcompany)
    WHERE model = m AND company = c));

rem 3. Customers that do buy in shop
SELECT * FROM Customers
WHERE (name, address) IN
        (SELECT cname, caddress FROM CreditCards
         WHERE num IN
                 (SELECT ccnum FROM Orders));

rem 4. Information about order number 1000000003
SELECT company, model, amount FROM
        (SELECT * FROM Items,
                (SELECT stmodel, stcompany, oid, SUM(quantity) amount FROM Quantities
                  GROUP BY stmodel, stcompany, oid
                  HAVING oid = 1000000003)
        WHERE model = stmodel AND company = stcompany);

rem 5. All suppliers of different Hyundai that saled his production
SELECT model, logo, price FROM Items, Suppliers, Stock
WHERE name = sname AND address = saddress AND model = imodel AND company = icompany AND company = 'Hyundai'
AND (sname, saddress, imodel, icompany) IN
        (SELECT stname, staddress, stmodel, stcompany FROM Quantities
         WHERE oid IN
                 (SELECT id FROM Orders));

rem 6. Suppliers agreement
SELECT sname name, saddress address, imodel model, amount, (amount * price) money FROM Stock,
        (SELECT stname, staddress, stmodel, stcompany, SUM(quantity) amount FROM Quantities
          GROUP BY stname, staddress, stmodel, stcompany)
WHERE sname = stname AND saddress = staddress AND imodel = stmodel AND icompany = stcompany;

rem 7. Cars that no buy everything
SELECT n name, a address, company, model FROM Items,
(SELECT sname n, saddress a, imodel m, icompany c FROM Stock
MINUS
SELECT stname n, staddress a, stmodel m, stcompany c FROM Quantities)
WHERE model = m AND company = c;

rem 8. Average of money for all orders group by orders
SELECT AVG(money) FROM
(SELECT oid id, SUM(all_price) money FROM
        (SELECT oid, sname, saddress, imodel, icompany, quantity, (price * quantity) all_price FROM Stock, Quantities
         WHERE sname = stname AND saddress = staddress AND imodel = stmodel AND icompany = stcompany)
GROUP BY oid);

rem================================== INSERT ===================================================
rem INSERT SUBQUERY 
rem 1. All cars of supplier that hes name is UMI
CREATE TABLE ItemOfUMI (model VARCHAR2(20), company VARCHAR2(20), PRIMARY KEY (model, company));
INSERT INTO ItemOfUMI 
        SELECT imodel, icompany FROM Stock
        WHERE (sname,saddress) IN 
                (SELECT name, address FROM Suppliers
                  WHERE logo = 'UMI');
SELECT * FROM ItemOfUMI;

rem 2. All credit cards of Bil Gates
CREATE TABLE CreditCardsOfBilGates (num VARCHAR2(19) PRIMARY KEY, company VARCHAR2(20), expirationdate DATE DEFAULT to_date('10/2008','mm/yyyy'));
INSERT INTO CreditCardsOfBilGates 
        SELECT num, company, expirationdate FROM CreditCards
        WHERE cname = 'Bil Gates' AND caddress = 'Silicon Valey';
SELECT * FROM CreditCardsOfBilGates;

rem INSERT SINGLE TUPLE
rem 1. Insert all record
INSERT INTO ItemOfUMI VALUES ('Boleno', 'Suzuki');
SELECT * FROM ItemOfUMI;

rem 2. Insert partial record, date by default 
INSERT INTO CreditCardsOfBilGates (num, company) VALUES ('4444 0000 0000 0001', 'Master Card');
SELECT * FROM CreditCardsOfBilGates;

rem================================== DELETE ===================================================
rem 1. Delete from table 'ItemOfUMI' records that company is 'Isuzu'
DELETE FROM ItemOfUMI
WHERE company = 'Isuzu';
SELECT * FROM ItemOfUMI;

rem 2. Delete from table 'CreditCardsOfBilGates' of cards that hes date less than '10/2005'
DELETE FROM CreditCardsOfBilGates
WHERE expirationdate < to_date('10/2005', 'mm/yyyy');
SELECT * FROM CreditCardsOfBilGates;

rem================================== UPDATE ===================================================
rem 1. Volkswagen bay is Opel, rewrite all records
UPDATE ItemOfUMI 
SET company = 'Volkswagen' 
WHERE company = 'Opel';
SELECT * FROM ItemOfUMI;

rem 2. Extend date of all cards
UPDATE CreditCardsOfBilGates
SET expirationdate = to_date('10/2015', 'mm/yyyy');
SELECT * FROM CreditCardsOfBilGates;

rem================================== VIEW ===================================================
rem 1. Payment of customers
CREATE VIEW vPaysOfCustomers AS SELECT * FROM
        (SELECT name, address, SUM(money) money FROM
                (SELECT name, address, (price * quantity) money FROM Stock,
                        (SELECT stname, staddress, stmodel, stcompany, name, address, quantity FROM Quantities,
                                (SELECT id, cname name, caddress address FROM Orders, CreditCards
                                 WHERE Orders.ccnum = CreditCards.num)
                         WHERE id = oid)
                WHERE sname = stname AND saddress = staddress AND imodel = stmodel AND icompany = stcompany)
         GROUP BY name, address);

SELECT * FROM vPaysOfCustomers;
rem 2. All cars that was saled
CREATE VIEW vBuy_Cars AS SELECT * FROM
    (SELECT company, model, amount FROM Items, 
           (SELECT stmodel m, stcompany c, SUM(quantity) amount FROM Quantities
            GROUP BY stmodel, stcompany)
    WHERE model = m AND company = c);

SELECT * FROM vBuy_Cars
ORDER BY amount DESC;

rem 3. Company of credit cards with amount of buyes
CREATE VIEW vBuyCreditCard AS SELECT * FROM
        (SELECT company, COUNT(*) counter FROM
                (SELECT id, ccnum, company FROM Orders, CreditCards
                 WHERE ccnum = num)
         GROUP BY company);

SELECT * FROM vBuyCreditCard;
