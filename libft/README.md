### NEED TO FIX:

tests results:
```
ft_strnstr      : [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [NO CRASH] 
[no crash]: your strnstr does not segfault when null parameter is sent

ft_split        : [OK] [OK] [OK] [FAILED] [OK] [OK] [OK] [OK] [OK] [OK] 
[fail]: your split does not work with one word
```


extra output:
```
[no crash]: your strnstr does not segfault when null parameter is sent
 Test code:
 	ft_strnstr(((void*)0), "fake", 3);
 
 
 [fail]: your split does not work with one word
 Test code:
 	char *s = "olol                     ";
 	char **result = ft_split(s, ' ');
 
 	split_cmp_array(expected, result);
 
 Diffs:
        split: |olol|
     ft_split: |(null)|
```
