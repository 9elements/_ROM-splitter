
main:
	rm *.out
	rm out/*
	/usr/bin/cc main.c && ./a.out
	cp ssdt1.asl out/
	cd out; iasl -f *.asl; cd ..

scp:
	scp out/* root@debian:/root/alexander/acpitables/manual/out
