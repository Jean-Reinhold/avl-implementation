.SILENT:
compile-run:
	clear
	echo "------> Compilando código"
	bash compile_multiple_libs.sh 
	
	echo "------> Código compilado"
	echo "------> Executando binário"
	./output.out

	echo "------> Destruindo binário"
	rm ./output.out