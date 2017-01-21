drop table newprice;
create table newprice(
	supplier_name varchar2(30),
	model varchar2(30),
	price number(10,2)
);
DECLARE
sname item.supplier_name%TYPE;
imodel item.model%TYPE;
price item.price%TYPE;
cursor prices(type varchar2) is select item.supplier_name,item.model,item.price from
	item where item.type=type;
BEGIN
	open prices('Mercedes');
	loop
	fetch prices into sname,imodel,price;
	exit when prices%NOTFOUND;
	price:=price+price*0.5;
	insert into newprice
		values(sname,imodel,price);
	end loop;
	close prices;
END;