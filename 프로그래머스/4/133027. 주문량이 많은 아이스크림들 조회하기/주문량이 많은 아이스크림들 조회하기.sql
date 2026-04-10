-- 코드를 입력하세요
SELECT j.FLAVOR
from FIRST_HALF f
join (
    select FLAVOR, sum(TOTAL_ORDER) as TOTAL_ORDER
    from JULY
    group by FLAVOR

) j on f.FLAVOR = j.FLAVOR
order by (j.TOTAL_ORDER + f.TOTAL_ORDER) desc
limit 3;