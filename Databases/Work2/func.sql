create or replace function IsCustomer(name varchar2,address varchar2) return boolean
is
n number;
begin
	if (name is null) or (address is null) then return true;
	end if;
	select count(*)  into n from cardof where customer_name=name and customer_address=address;
	if n>0 then return true;
	else return false;
	end if;
end IsCustomer;