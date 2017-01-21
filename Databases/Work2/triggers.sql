create or replace trigger validcard
after update of card_exp_date on orderedby
for each row
begin
where(:old.card_exp_date<:new.card_exp_date)
	update orderedby
	set card_exp_date=:new.card_exp_date
	where orders_id=:new.orders_id

end validcard;

create or replace trigger validsupplier
before insert on item
for each row
declare
n number;
begin
	select count(*) into n from supplier where name=:new.supplier_name;
	if n>0 then
	insert into item
		values(:new.supplier_name,:new.model,:new.type,:new.price);
	end if;
end validsupplier;