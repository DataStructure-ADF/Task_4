#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) diset Nil
    */
    //------------- YOUR CODE HERE -------------
    first(L) = NULL;
    //----------------------------------------
}

address allocate(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x,
    *      next dan prev elemen = Nil
    */

    address P = NULL;
    //------------- YOUR CODE HERE -------------
    P = new elmlist;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    //----------------------------------------
    return P;
}

void deallocate(address &P) {
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    //------------- YOUR CODE HERE -------------
    delete P;
    //----------------------------------------
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    //------------- YOUR CODE HERE -------------
    if (first(L)!=NULL) {
        prev(P) = prev(first(L));
        next(P) = first(L);
        next(prev(P)) = P;
        prev(first(L)) = P;
        first(L) = P;
    } else {
        first(L) = P;
        next(P) = P;
        prev(P) = P;
    }
    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //------------- YOUR CODE HERE -------------
    if (first(L)!=NULL) {
        next(P) = first(L);
        prev(P) = prev(first(L));
        next(prev(P)) = P;
        prev(first(L)) = P;
    } else {
        first(L) = P;
        next(P) = P;
        prev(P) = P;
    }
    //----------------------------------------
}

address findElmByID(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
    //------------- YOUR CODE HERE -------------
    P = first(L);
    if (P!=NULL) {
        while ((next(P)!=first(L))&&(info(P).ID!=x.ID)) {
            P = next(P);
        }
        if (info(P).ID==x.ID) {
            return P;
        } else {
            return NULL;
        }
    }
    cout << "im out" << endl;
    //----------------------------------------
    return P;
}

address findElmByName(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.name = x.name,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
    //------------- YOUR CODE HERE -------------
    P = first(L);
    if (P!=NULL) {
        while ((next(P)!=first(L))&&(info(P).name!=x.name)) {
            P = next(P);
        }
        if (info(P).name==x.name) {
            return P;
        } else {
            return NULL;
        }
    }
    //----------------------------------------
    return P;
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //------------- YOUR CODE HERE -------------
    if (first(L)!=NULL){
        P = first(L);
        if (next(P)!=P) {
            first(L) = next(P);
            prev(first(L)) = prev(P);
            next(prev(P)) = first(L);
            next(P) = NULL;
            prev(P) = NULL;
        } else {
            first(L) = NULL;
            next(P) = NULL;
            prev(P) = NULL;
        }
    }
    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //------------- YOUR CODE HERE -------------
    if (first(L)!=NULL){
        P = prev(first(L));
        if (next(P)!=P) {
            prev(first(L)) = prev(P);
            next(prev(P)) = first(L);
            next(P) = NULL;
            prev(P) = NULL;
        } else {
            first(L) = NULL;
            next(P) = NULL;
            prev(P) = NULL;
        }
    }
    //----------------------------------------
}

void insertAfter(List &L, address &Prec, address P) {
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    //------------- YOUR CODE HERE -------------
    if ((Prec!=NULL)&&(P!=NULL)) {
        next(P) = next(Prec);
        prev(next(P)) = P;
        next(Prec) = P;
        prev(P) = P;
    }
    //----------------------------------------

}
void deleteAfter(List &L, address &Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //------------- YOUR CODE HERE -------------
    if (Prec!=NULL) {
        if (next(Prec)!=first(L)) {
            P = next(Prec);
            next(Prec) = next(P);
            prev(next(P)) = Prec;
            next(P) = NULL;
            prev(P) = NULL;
        } else if (Prec!=first(L)) {
            P = next(Prec);
            first(L) = next(P);
            next(Prec) = next(P);
            prev(next(P)) = Prec;
            next(P) = NULL;
            prev(P) = NULL;
        } else {
            P = Prec;
            first(L) = NULL;
            next(P) = NULL;
            prev(P) = NULL;
        }
    }
    //----------------------------------------
}

