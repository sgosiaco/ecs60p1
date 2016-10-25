#! /bin/tcsh

echo This script assumes that your timetest program is named a.out.
echo The times of the three runs for each ADT are placed in the file \"results\"
echo "File ADT# Time#1  Ignore" > results

set ADT = 11

while ($ADT < 12)
  set fileNum = 1
  while ($fileNum < 2)
    echo File{$fileNum}.dat > tt.tmp
    echo Running File{$fileNum}.dat once for ADT $ADT
    echo $ADT >> tt.tmp

    if [ $ADT -eq 11 ]; then
      echo 1000000 >> tt.tmp

      echo $ADT >> tt.tmp
      echo 500000 >> tt.tmp

      echo $ADT >> tt.tmp
      echo 50000 >> tt.tmp

      echo $ADT >> tt.tmp
      echo 5000 >> tt.tmp

      echo $ADT >> tt.tmp
      echo 500 >> tt.tmp
      echo Load factor 0.5 1 10 100 1000 >> results
      echo HT Size 1000000 500000 50000 5000 500 >> results
    fi

    echo 0 >> tt.tmp
    echo -n File{$fileNum}  $ADT "  " >> results
    a.out < tt.tmp | awk '/CPU/ {printf("%s     ", $6)}' >> results
    echo " " >> results
    @ fileNum ++
  end # while more files

  @ ADT ++
end # while more ADTs
