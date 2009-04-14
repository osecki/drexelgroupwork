define addr 
proc(n)
  if n then return := n + addr(n-1) else return := 0 fi
end;
n := 5;
s := addr(n)
