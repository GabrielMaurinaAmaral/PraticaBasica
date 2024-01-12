select * from clientes
--colunas
select clientes, sexo, status from clientes
--filtro
select cliente, sexo, status from clientes where status = 'Silver'
--or
select cliente, sexo, status from clientes where status = 'Silver' OR status = 'Platinum'
--in
select cliente, sexo, status from clientes where status IN ('Silver','Platinum')
--like
select cliente, sexo, status from clientes where cliente like '%Alb%'
-->
select * from vendas where total > 6000
--ordenção
select cliente from clientes
order by cliente

select cliente from clientes
order by cliente DESC

select cliente, status from clientes
order by cliente desc, status 
--BETWEEN
select * from vendas where total between 6000 and 8000
--limit
select  * from VENDAS limit 10
--distinct
select distinct status from clientes
--agregação
select count(*) from vendas
--agregação com where
select count(*) from vendas where total > 6000
--agrupando
select idvendedor, count(idvendedor) from vendas group by idvendedor
--having
select idvendedor, count(idvendedor) from vendas group by idvendedor
having count(idvendedor) > 40
--join com where
select nome, total from vendas, vendedores
where vendas.idvendedor = vendedores.idvendedor
--inner join
select count(*) from vendasinner join vendedores on(vendas.idvendedor = vendedores.idvendedor )
--left join
select count(*)  from vendas
left join vendedores on 
(   vendas.idvendedor = vendedores.idvendedor   )
--right join
INSERT INTO vendedores(nome) VALUES ('Fernando Amaral');
select count(*)  from vendas right join vendedores on( vendas.idvendedor = vendedores.idvendedor );
--apelidos
select cliente, total from vendas v
inner join clientes c on (v.idcliente = c.idcliente)














