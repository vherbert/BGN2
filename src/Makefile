# COMMENTAIRES EN FIN DE FICHIER

CPP = g++
CPPFLAGS = -std=c++14 -I ../include -I ../gengetopt -I  ../dclxvi-20130329  -O2  -Wextra -fPIC -fopenmp  -D_GLIBCXX_USE_CXX11_ABI=0 
# -g et -pg rajoutés à la compilation et à l'édition de lien pour profiler le programme 
# -fprofile-arcs -ftest-coverage rajoutés à la compilation et à l'édition de lien pour couvrir le programme
LDFLAGS =-Wall  -Wextra -fopenmp -lgmp -lgmpxx #-g -pg 
EXEC = bgn bgn_check bgn_as 

#chemin sans fichier
HDRPATH = ../include
SRCPATH = ../src
OBJPATH = ../obj
BINPATH = ../bin
LIBPATH = ../lib
666PATH = ../dclxvi-20130329
VPATH   = $(SRCPATH):$(666PATH):../gengetopt 
#UPDPATH = ../update

#fichier avec chemin
HDR 	      = $(wildcard $(HDRPATH)/*.h*)
ALL_SRC		  = $(wildcard $(SRCPATH)/*.c*)
SRC           = $(filter-out $(SRCPATH)/test_quadruplet.cpp, $(ALL_SRC)) 
OBJ		      = $(patsubst $(SRCPATH)/%.cpp,$(OBJPATH)/%.o,$(SRC))
OBJ_CHECK     = $(patsubst $(SRCPATH)/%.cpp,$(OBJPATH)/%_check.o,$(SRC))
OBJ_AS        = $(patsubst $(SRCPATH)/%.cpp,$(OBJPATH)/%_as.o,$(SRC))
ALL_SRC_666	  = $(wildcard $(666PATH)/*.c*)
SRC_666       = $(filter-out $(666PATH)/bilintest.c $(666PATH)/speedtest.c  $(666PATH)/test_curvepoint_multiscalar.c  $(666PATH)/test_twistpoint_multiscalar.c $(666PATH)/twistpoint_fp2_multiscalar.c $(666PATH)/curvepoint_fp_multiscalar.c, $(ALL_SRC_666))
ASS_666		  = $(wildcard $(666PATH)/*.s)
#HDR_UPD	      = $(wildcard $(UPDPATH)/*.h)
#SRC_UPD       = $(wildcard $(UPDPATH)/*.c)
#ASS_UPD       = $(wildcard $(UPDPATH)/*.s)
OBJ_666   	  = $(patsubst $(666PATH)/%.c,$(OBJPATH)/%_666.o,$(SRC_666)) 
#$(patsubst $(UPDPATH)/%.c,$(OBJPATH)/%.o,$(SRC_UPD))
OBJ_666_CHECK = $(patsubst $(666PATH)/%.c,$(OBJPATH)/%_666_check.o,$(SRC_666)) 
#$(patsubst $(UPDPATH)/%.c,$(OBJPATH)/%_check.o,$(SRC_UPD))
OBJ_666_AS    = $(patsubst $(666PATH)/%.c,$(OBJPATH)/%_666_as.o,$(SRC_666)) $(patsubst $(666PATH)/%.s,$(OBJPATH)/%_666_as.o,$(ASS_666)) 
#$(patsubst $(UPDPATH)/%.c,$(OBJPATH)/%_as.o,$(SRC_UPD)) $(patsubst $(UPDPATH)/%.s,$(OBJPATH)/%_as.o,$(ASS_UPD))
LIB    = $(filter-out $(OBJPATH)/option.o $(OBJPATH)/bgn.o $(OBJPATH)/circuit_additionL1.o $(OBJPATH)/circuit_additionL2.o $(OBJPATH)/circuit_additionL3.o $(OBJPATH)/circuit_additionL4.o $(OBJPATH)/circuit_chiffrement.o $(OBJPATH)/circuit_minmaj.o $(OBJPATH)/circuit_minmaj2.o $(OBJPATH)/circuit_minmaj3.o $(OBJPATH)/circuit_multiplicationL1.o $(OBJPATH)/circuit_multiplicationL1L2.o $(OBJPATH)/circuit_multiplicationL2.o $(OBJPATH)/circuit_size.o, $(OBJPATH)/circuit_scalar_product.o, $(OBJPATH)/circuit_time.o, $(OBJPATH)/circuit_time2.o , $(OBJ)) 
LIB_CHECK   = $(filter-out $(OBJPATH)/option.o $(OBJPATH)/bgn_check.o $(OBJPATH)/circuit_additionL1_check.o $(OBJPATH)/circuit_additionL2_check.o $(OBJPATH)/circuit_additionL3_check.o $(OBJPATH)/circuit_additionL4_check.o $(OBJPATH)/circuit_chiffrement_check.o $(OBJPATH)/circuit_minmaj_check.o $(OBJPATH)/circuit_minmaj2_check.o $(OBJPATH)/circuit_minmaj3_check.o $(OBJPATH)/circuit_multiplicationL1_check.o $(OBJPATH)/circuit_multiplicationL1L2_check.o $(OBJPATH)/circuit_multiplicationL2_check.o $(OBJPATH)/circuit_size_check.o ,$(OBJPATH)/circuit_scalar_product_check.o, $(OBJPATH)/circuit_time_check.o, $(OBJPATH)/circuit_time2_check.o , $(OBJ_CHECK)) 
LIB_AS   = $(filter-out $(OBJPATH)/option.o $(OBJPATH)/bgn_as.o $(OBJPATH)/circuit_additionL1_as.o $(OBJPATH)/circuit_additionL2_as.o $(OBJPATH)/circuit_additionL3_as.o $(OBJPATH)/circuit_additionL4_as.o $(OBJPATH)/circuit_chiffrement_as.o $(OBJPATH)/circuit_minmaj_as.o $(OBJPATH)/circuit_minmaj2_as.o $(OBJPATH)/circuit_minmaj3_as.o $(OBJPATH)/circuit_multiplicationL1_as.o $(OBJPATH)/circuit_multiplicationL1L2_as.o $(OBJPATH)/circuit_multiplicationL2_as.o $(OBJPATH)/circuit_size_as.o ,$(OBJPATH)/circuit_scalar_product_as.o, $(OBJPATH)/circuit_time_as.o, $(OBJPATH)/circuit_time2_as.o , $(OBJ_AS)) 
all:  $(EXEC)

bgn: $(OBJ) $(OBJPATH)/option.o $(OBJ_666)  $(OBJPATH)/scalar_sub_nored_666_as.o $(OBJPATH)/heap_rootreplaced_666_as.o
	$(CPP) -o $(BINPATH)/$@ $+ $(LDFLAGS)

bgn_check: $(OBJ_CHECK) $(OBJPATH)/option.o $(OBJ_666_CHECK) $(OBJPATH)/scalar_sub_nored_666_as.o $(OBJPATH)/heap_rootreplaced_666_as.o 
	$(CPP) -o $(BINPATH)/$@ $+ $(LDFLAGS)
	
bgn_as: $(OBJ_AS) $(OBJPATH)/option.o   $(OBJ_666_AS)
	$(CPP) -o $(BINPATH)/$@ $+ $(LDFLAGS)

lib:
	@gcc -shared -fPIC -o $(LIBPATH)/libbgnfcf.so $(LIB)

lib_check:
	@gcc -shared -fPIC -o $(LIBPATH)/libbgnfcf_check.so $(LIB_CHECK)	

lib_as:
	@gcc -shared -fPIC -o $(LIBPATH)/libbgnfcf_as.so $(LIB_AS)	
	
bgn_lib: $(OBJPATH)/option.o $(OBJ_666)  $(OBJPATH)/scalar_sub_nored_666_as.o $(OBJPATH)/heap_rootreplaced_666_as.o	 $(OBJPATH)/bgn.o $(OBJPATH)/circuit_additionL1.o $(OBJPATH)/circuit_additionL2.o $(OBJPATH)/circuit_additionL3.o $(OBJPATH)/circuit_additionL4.o $(OBJPATH)/circuit_chiffrement.o $(OBJPATH)/circuit_minmaj.o $(OBJPATH)/circuit_minmaj2.o $(OBJPATH)/circuit_minmaj3.o $(OBJPATH)/circuit_multiplicationL1.o $(OBJPATH)/circuit_multiplicationL1L2.o $(OBJPATH)/circuit_multiplicationL2.o $(OBJPATH)/circuit_size.o $(OBJPATH)/circuit_demo.o  $(OBJPATH)/circuit_scalar_product.o $(OBJPATH)/circuit_time.o $(OBJPATH)/circuit_time2.o
	$(CPP) -o $(BINPATH)/$@ $+ $(LDFLAGS) -L ../lib -lbgnfcf

bgn_lib_check: $(OBJPATH)/option.o $(OBJ_666_CHECK)  $(OBJPATH)/scalar_sub_nored_666_as.o $(OBJPATH)/heap_rootreplaced_666_as.o	 $(OBJPATH)/bgn_check.o $(OBJPATH)/circuit_additionL1_check.o $(OBJPATH)/circuit_additionL2_check.o $(OBJPATH)/circuit_additionL3_check.o $(OBJPATH)/circuit_additionL4_check.o $(OBJPATH)/circuit_chiffrement_check.o $(OBJPATH)/circuit_minmaj_check.o $(OBJPATH)/circuit_minmaj2_check.o $(OBJPATH)/circuit_minmaj3_check.o $(OBJPATH)/circuit_multiplicationL1_check.o $(OBJPATH)/circuit_multiplicationL1L2_check.o $(OBJPATH)/circuit_multiplicationL2_check.o $(OBJPATH)/circuit_size_check.o  $(OBJPATH)/circuit_scalar_product_check.o $(OBJPATH)/circuit_time_check.o $(OBJPATH)/circuit_time2_check.o
	$(CPP) -o $(BINPATH)/$@ $+ $(LDFLAGS) -L ../lib -lbgnfcf_check
	
bgn_lib_as:  $(OBJPATH)/option.o   $(OBJ_666_AS) $(OBJPATH)/bgn_as.o $(OBJPATH)/circuit_additionL1_as.o $(OBJPATH)/circuit_additionL2_as.o $(OBJPATH)/circuit_additionL3_as.o $(OBJPATH)/circuit_additionL4_as.o $(OBJPATH)/circuit_chiffrement_as.o $(OBJPATH)/circuit_minmaj_as.o $(OBJPATH)/circuit_minmaj2_as.o $(OBJPATH)/circuit_minmaj3_as.o $(OBJPATH)/circuit_multiplicationL1_as.o $(OBJPATH)/circuit_multiplicationL1L2_as.o $(OBJPATH)/circuit_multiplicationL2_as.o $(OBJPATH)/circuit_size_as.o   $(OBJPATH)/circuit_scalar_product_as.o  $(OBJPATH)/circuit_time_as.o $(OBJPATH)/circuit_time2_as.o 
	$(CPP) -o $(BINPATH)/$@ $+ $(LDFLAGS) -L ../lib -lbgnfcf_as
	
test_quadruplet_check: $(OBJPATH)/test_quadruplet_check.o $(OBJPATH)/BitChiffre_check.o $(OBJPATH)/quadruplet_check.o $(OBJPATH)/$(OBJPATH)/fpe2scalar_check.o  $(OBJ_666_CHECK) $(OBJPATH)/scalar_sub_nored_666_as.o $(OBJPATH)/heap_rootreplaced_666_as.o $(OBJPATH)/Bipoint_check.o 
	$(CPP) $(LDFLAGS) -o $(BINPATH)/$@ $+
	
test_quadruplet_as: $(OBJPATH)/test_quadruplet_as.o $(OBJPATH)/BitChiffre_as.o $(OBJPATH)/quadruplet_as.o $(OBJ_666_AS) $(OBJPATH)/Bipoint_as.o $(OBJPATH)/$(OBJPATH)/fpe2scalar_as.o
	$(CPP) $(LDFLAGS) -o $(BINPATH)/$@ $+
		
option : option.ggo
	@gengetopt < $<  --file-name=option --output-dir=../gengetopt --unamed-opts

.PHONY: clean	

clean:
	@rm -rf $(OBJPATH)/*.o  $(BINPATH)/bgn $(BINPATH)/bgn_as $(BINPATH)/bgn_check $(BINPATH)/bgn_lib $(BINPATH)/bgn_lib_as $(BINPATH)/bgn_lib_check prof *.exe *.db *.do *.gch *.out $(OBJPATH)/*.gcda $(OBJPATH)/*.gcno *.gcov callgrind.out.*


profile: 
	@read -p "Enter binary name: " binary && gprof -l $(BINPATH)/$$binary gmon.out >| profile_line && gprof $(BINPATH)/$$binary gmon.out >| profile_function 
# le fichier gmon.out est crée après avoir executé le programme, il ne suffit pas de compiler et d'éditer les liens avec -g -pg 
# read pour demander au maker d'affecter une variable
# $$ pour acceder à cette valeur (elle est définie dans les build commands, pas dans le makefile)
# && parce que la valeur n'est pas mémorisée

tata=4
fun:
	export toto=5
	sleep 5 && echo $$toto
	toto=3; echo $$toto
	echo $(tata)		
	
graph:
	@gprof2dot profile_function >| graph_function.dot
	@dot -T png -o graph_function.png graph_function.dot
	@feh graph_function.png&
	
doc:
	cd .. && doxygen  doc/doxygen_conf && firefox doc/html/annotated.html&


gdb: 
	gdb run ../bin/bgn_as	
	
valgrind:
	valgrind --track-origins=yes --leak-check=full  --show-leak-kinds=all  ../bin/bgn_as -s ""
	
print-%:
	@echo '$*=$($*)'

$(OBJPATH)/option.o : option.c 
	$(CPP) $(CPPFLAGS) -o $@ -c $<	
		
$(OBJPATH)/%.o : %.cpp $(HDR) 
	$(CPP) $(CPPFLAGS) -o $@ -c $<	

$(OBJPATH)/%_check.o :	%.cpp $(HDR) 
	$(CPP) $(CPPFLAGS) -DCHECK -DNBTESTS=10 -o $@ -c $<	
	
$(OBJPATH)/%_as.o :	%.cpp $(HDR) 
	$(CPP) $(CPPFLAGS) -DQHASM -DNBTESTS=10 -o $@ -c $<		
		
$(OBJPATH)/%_666.o :	$(666PATH)/%.c $(666PATH)/%.h 
	$(CPP) $(CPPFLAGS) -o $@ -c $<		
		
$(OBJPATH)/%_666_check.o :	$(666PATH)/%.c $(666PATH)/%.h
	$(CPP) $(CPPFLAGS) -DCHECK  -o $@ -c $<	
	
$(OBJPATH)/%_666_as.o :	$(666PATH)/%.c $(666PATH)/%.h
	$(CPP) $(CPPFLAGS) -DQHASM  -o $@ -c $<		

$(OBJPATH)/%_666_as.o :	$(666PATH)/%.s
	$(CPP) $(CPPFLAGS) -o $@ -c $<	
	
#$(OBJPATH)/%.o :	$(UPDPATH)/%.c  $(HDR_UPD)
#	$(CPP) $(CPPFLAGS) -o $@ -c $<	

#$(OBJPATH)/%_check.o :	$(UPDPATH)/%.c $(HDR_UPD)
#	$(CPP) $(CPPFLAGS) -DCHECK  -o $@ -c $<	
	
#$(OBJPATH)/%_as.o :	$(UPDPATH)/%.c $(HDR_UPD)
#	$(CPP) $(CPPFLAGS) -DQHASM  -o $@ -c $<	

#$(OBJPATH)/%_as.o :	$(UPDPATH)/%.s
#	$(CPP) $(CPPFLAGS) -o $@ -c $<	
		
#$(OBJPATH)/asfunctions.a: $(OBJPATH)/fp2e_add2.o $(OBJPATH)/fp2e_sub2.o \
#	$(OBJPATH)/fp2e_double2.o $(OBJPATH)/fp2e_triple2.o $(OBJPATH)/fp2e_neg2.o \
#	$(OBJPATH)/fp2e_mul.o $(OBJPATH)/fp2e_mul_fpe.o $(OBJPATH)/fp2e_short_coeffred.o \
#	$(OBJPATH)/fp2e_add.o $(OBJPATH)/fp2e_sub.o $(OBJPATH)/fp2e_parallel_coeffmul.o $(OBJPATH)/fp2e_mulxi.o\
#	$(OBJPATH)/fp2e_double.o $(OBJPATH)/fp2e_triple.o $(OBJPATH)/fp2e_neg.o $(OBJPATH)/fp2e_conjugate.o \
#	$(OBJPATH)/fpe_mul.o $(OBJPATH)/fp2e_square.o \
#	$(OBJPATH)/consts.o
#	rm -f $(OBJPATH)/asfunctions.a
#	ar cr $(OBJPATH)/asfunctions.a $^

