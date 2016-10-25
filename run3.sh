#! /bin/tcsh

echo This script assumes that your timetest program is named a.out.
echo The times of the three runs for each ADT are placed in the file \"results\"
echo "File ADT# Time#1  Ignore" > results

set ADT = 8

while ($ADT < 15)
  set fileNum = 1
  while ($fileNum < 5)
    echo File{$fileNum}.dat > tt.tmp
    echo Running File{$fileNum}.dat once for ADT $ADT
    echo $ADT >> tt.tmp

    if( $ADT == 10 ) then
      echo 3 >> tt.tmp
      echo 1 >> tt.tmp

      echo $ADT >> tt.tmp
      echo 3 >> tt.tmp
      echo 200 >> tt.tmp

      echo $ADT >> tt.tmp
      echo 1000 >> tt.tmp
      echo 2 >> tt.tmp

      echo $ADT >> tt.tmp
      echo 1000 >> tt.tmp
      echo 200 >> tt.tmp
      echo M,L 3,1  3,200 1000,2  1000,200
    fi

    if ( $ADT == 11 ) then
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
    endif

    if ( $ADT == 12 ) then
      echo 5000000 >> tt.tmp

      echo $ADT >> tt.tmp
      echo 2000000 >> tt.tmp

      echo $ADT >> tt.tmp
      echo 1000000 >> tt.tmp

      echo $ADT >> tt.tmp
      echo 500000 >> tt.tmp

      echo $ADT >> tt.tmp
      echo 250000 >> tt.tmp
      echo Load factor 0.1 .25 .5 1 2 >> results
      echo HT Size 5000000 2000000 1000000 500000 250000 >> results
    fi

    if( $ADT == 14 ) then
      echo 5000000 >> tt.tmp

      echo $ADT >> tt.tmp
      echo 2000000 >> tt.tmp

      echo $ADT >> tt.tmp
      echo 1000000 >> tt.tmp

      echo $ADT >> tt.tmp
      echo 500000 >> tt.tmp

      echo $ADT >> tt.tmp
      echo 250000 >> tt.tmp
      echo Load factor 0.1 .25 .5 1 2 >> results
      echo HT Size 5000000 2000000 1000000 500000 250000 >> results
    fi

    echo 0 >> tt.tmp
    echo -n File{$fileNum}  $ADT "  " >> results
    timetest3.out < tt.tmp | awk '/CPU/ {printf("%s     ", $15)}' >> results
    echo " " >> results
    @ fileNum ++
  end # while more files

  @ ADT ++
end # while more ADTs
