create or replace procedure AddItems(supplier_name varchar2,model varchar2,type varchar2,price number)
is
n1 number;
n2 number;
n3 number;
begin
	select count(*) into n1 from supplier where supplier_name=name;
	select count(*) into n2 from item where item.model=model;
	select count(*) into n3 from item where item.supplier_name=supplier_name;
	if n1=0 then raise_application_error(-20330 , 'ERROR: Supplier does not exist');
	else
	if n2>0 and n3>0 then raise_application_error(-20330 , 'ERROR: Item already exist');
	else
	insert into item
		values(supplier_name,model,type,price);
	end if;
	end if;
end AddItems;