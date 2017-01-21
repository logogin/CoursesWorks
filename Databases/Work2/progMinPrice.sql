drop table minprice;
create table minprice(
supplier_name varchar2(30),
item_type varchar2(30),
item_model varchar2(30),
item_price number(10,2)
);
DECLARE
cursor prices is select supplier_name,type,model,min(price) as price 
	from item group by supplier_name,model,type;
my_row prices%ROWTYPE;
BEGIN
	open prices;
	loop
	fetch prices into my_row;
	exit when prices%NOTFOUND;
	insert into minprice
		values(my_row.supplier_name,my_row.type,my_row.model,my_row.price);
	end loop;
	close prices;
END;