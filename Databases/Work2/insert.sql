insert into supplier 
	values('UMI Opel','Rishon Le Tsion','UMI');
insert into supplier
	values('UMI Buick','Rishon Le Tsion','UMI');
insert into supplier
	values('UMI Isuzu','Rishon Le Tsion','UMI');
insert into supplier
	values('Chempion Audi','Bney Brack','Chempion');
insert into supplier
	values('Colmobile Mercedes', 'Tel Aviv','Colmobile');
insert into supplier
	values('Colmobile Hyundai','Tel Aviv','Colmobile');
insert into supplier
	values('M.C.I. Porshe','Tel Aviv','M.C.I.');
insert into supplier
	values('Delek Motors Hyundai','Tel Aviv','Delek Motors');
insert into supplier
	values('Delek Motors Isuzu','Tel Aviv','Delek Motors');
/*9 supliers*/

insert into item 
	Values('UMI Opel','Corsa TDI','Opel',86000);
insert into item 
	Values('UMI Opel','Astra Station','Opel',126000);
insert into item 
	Values('UMI Opel','Omega','Opel',235000);
insert into item 
	Values('UMI Buick','Custom','Buick',251000);
insert into item 
	Values('UMI Isuzu','Trooper','Isuzu',210000);
insert into item 
	Values('UMI Isuzu','Ippon','Isuzu',120000);
insert into item 
	Values ('Chempion Audi','A6','Audi',300000);
insert into item 
	Values('Chempion Audi','TT','Audi',300000);
insert into item 
	Values('Chempion Audi','A8','Audi',600000);
insert into item 
	Values('Chempion Audi','Allroad','Audi',420000);
insert into item 
	Values('Colmobile Mercedes','A Class','Mercedes',150000);
insert into item 
	Values('Colmobile Mercedes','E Class','Mercedes',350000);
insert into item 
	Values('Colmobile Mercedes','S Class','Mercedes',600000);
insert into item 
	Values('Colmobile Mercedes','M Class','Mercedes',400000);
insert into item 
	Values('Colmobile Hyundai','Eccent','Hyundai',90000);
insert into item 
	Values('Colmobile Hyundai','Sanata','Hyundai',130000);
insert into item 
	Values('Colmobile Hyundai','Glooper','Hyundai', 150000);
insert into item 
	Values('M.C.I. Porshe','Boxter','Porshe',450000);
insert into item 
	Values('M.C.I. Porshe','911','Porshe',1200000);
insert into item 
	Values('Delek Motors Hyundai','Sanata','Hyundai',92000);
insert into item 
	Values('Delek Motors Isuzu','Ippon','Isuzu',125000);
/*21 item*/

insert into orders 
	values(1111,to_date('18-01-2003','DD-MM-YYYY'));
insert into orders
	values(2222,to_date('28-11-2002','DD-MM-YYYY'));
insert into orders
	values(3333,to_date('07-12-2001','DD-MM-YYYY'));
insert into orders
	values(4444,to_date('24-04-2003','DD-MM-YYYY'));
insert into orders
	values(5555,to_date('12-03-2003','DD-MM-YYYY'));
/*5 orders*/

insert into quantity 
	values('Colmobile Hyundai','Eccent',1111, 5);
insert into quantity 
	values('Colmobile Mercedes','E Class',1111, 1);
insert into quantity 
	values('UMI Isuzu','Ippon',2222,2);
insert into quantity 
	values('UMI Isuzu','Trooper',2222, 2);
insert into quantity 
	values ('Colmobile Hyundai','Glooper',2222,2);
insert into quantity 
	values ('Colmobile Mercedes','E Class',3333,5);
insert into quantity 
	values ('Colmobile Mercedes','M Class',3333,5);
insert into quantity 
	values ('Colmobile Mercedes','S Class',3333,1);
insert into quantity 
	values ('Chempion Audi','TT',4444,1);
insert into quantity 
	values ('Chempion Audi','A8',4444, 1);
insert into quantity 
	values ('M.C.I. Porshe','911',4444,1);
insert into quantity 
	values ('Delek Motors Hyundai','Sanata',5555,3);
insert into quantity 
	values ('Colmobile Hyundai','Sanata',5555,3);
/*13 quantities*/

insert into cardof
	values(1100110011,'Mickey Williams','New York','mwill@hotmail.com');
insert into cardof
	values(2200220022,'Anri France','Paris','calavara@almanah.uk');
insert into cardof
	values(3300330033,'Gandel DeMarn','New Mexico','chupachups@sweety.us');
insert into cardof
	values(4400440044,'Arman Harman','Los Angeles','harm@spyglass.com');
insert into cardof
	values(5500550055,'Darel Hickman','London','lerad@syspages.uk');
insert into cardof
	values(6600660066,'Arman Harman','Los Angeles','harm@spyglass.com');
insert into cardof
	values(7700770077,'Anri France','Paris','calavara@almanah.uk');
/*7 cardsof*/

insert into orderedby
	values(1111,1100110011,'VISA',to_date('12-03-2005','DD-MM-YYYY'));
insert into orderedby
	values(2222,4400440044,'American Express',to_date('03-07-2004','DD-MM-YYYY'));
insert into orderedby
	values(3333,6600660066,'Dinners Club',to_date('15-12-2006','DD-MM-YYYY'));
insert into orderedby
	values(4444,2200220022,'Master Card',to_date('24-10-2005','DD-MM-YYYY'));
insert into orderedby
	values(5555,7700770077,'VISA',to_date('17-04-2004','DD-MM-YYYY'));
/*5 orderedbys*/