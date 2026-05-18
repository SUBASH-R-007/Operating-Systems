
#!/bin/bash
echo "ENTER TWO NUMBERS : "
read a b
add=`expr $a + $b`
sub=`expr $a - $b`
mult=`expr $a \* $b`
div=`expr $a / $b`
echo "Sum : $add Difference : $sub Product : $mult Quotient : $div"
sum=$(($a + $b))
diff=$(($a - $b))
prod=$(($a * $b))
div=$(($a / $b))
echo "Sum : $sum Difference : $diff Product : $prod Quotient : $div"
