#include<bits/stdc++.h>
#include<windows.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<iomanip>

    using namespace std;

    // Nguyên Liệu
    struct NL{
        int maNL;
        char tenNL[50];
        int soluongNL;
        float giaNL;
        char nguonnhapNL[50];
    };

    struct NodeNL{
        NL infoNL;
        struct NodeNL *nlnext;
        struct NodeNL *nlprev;
    };

    struct ListNL{
        NodeNL *nlHead;
        NodeNL *nlTail;
    };

    void initNL(ListNL &lnl){
        lnl.nlHead = lnl.nlTail = NULL;
    }

    NodeNL *createNodeNL(NL nl){
        NodeNL *p = new NodeNL;
        if( p == NULL) exit(1);
        p ->infoNL = nl;
        p ->nlnext = NULL;
        p ->nlprev = NULL;
        return p;
    }

    void input1(NL &nl){
        cout<<"\nNhap ma nguyen lieu: ";
        cin>>nl.maNL;
        cout<<"\nNhap ten nguyen lieu: ";
        fflush(stdin);
        gets(nl.tenNL);
        cout<<"\nNhap so luong nguyen lieu: ";
        cin>>nl.soluongNL;
        cout<<"\nNhap gia nguyen lieu: ";
        cin>>nl.giaNL;
        cout<<"\nNhap nguon nhap: ";
        fflush(stdin);
        gets(nl.nguonnhapNL);
        cout<<endl;
    }

    void output1(NL nl){
        cout<<endl<<nl.maNL<<setw(10)<<nl.tenNL<<setw(15)<<nl.soluongNL<<setw(15)<<nl.giaNL<<setw(20)<<nl.nguonnhapNL;
        cout<<endl;
    }

    void chendauNL(ListNL &lnl, NodeNL *p){
        if(lnl.nlHead == NULL ){
            lnl.nlHead = lnl.nlTail = p;
        }
        else {
            p ->nlnext = lnl.nlHead;
               lnl.nlHead ->nlprev = p;
               lnl.nlHead = p;
        }
    }

    void chencuoiNL(ListNL &lnl, NodeNL *p){
        if(lnl.nlHead == NULL ){
            lnl.nlHead = lnl.nlTail = p;
        }
        else {
            lnl.nlTail ->nlnext = p;
            p ->nlprev = lnl.nlTail;
            lnl.nlTail = p;
        }
    }

    void inputlistNL(ListNL &lnl){
        NL nl;
        int n;
        cout<<"\nNhap so luong: ";
        cin>>n;
        for(int i = 1; i <= n; i++){
            input1(nl);
            NodeNL *p = createNodeNL(nl);
            chencuoiNL(lnl, p);
        }
    }

    void outputlistNL(ListNL lnl){
        cout<<"\nDanh sach nguyen lieu la: "<<endl;
        cout<<endl<<"maNL"<<setw(10)<<"tenNL"<<setw(15)<<"soluongNL"<<setw(15)<<"giaNL"<<setw(20)<<"nguonnhapNL";
        cout<<endl;
        for(NodeNL * p = lnl.nlHead; p != NULL; p = p->nlnext){
            output1(p ->infoNL);
        }
    }

     void themNLdauds(ListNL &lnl){
          NL nl;
          cout<<"\nNhap thong tin Nguyen Lieu can them: ";
          cout<<endl;
          input1(nl);
          NodeNL *p = createNodeNL(nl);
          chendauNL(lnl, p);
          cout<<endl;
     }

     void themNLcuoids(ListNL &lnl){
          NL nl;
          cout<<"\nNhap thong tin Nguyen Lieu can them: ";
          cout<<endl;
          input1(nl);
          NodeNL *p = createNodeNL(nl);
          chencuoiNL(lnl, p);
          cout<<endl;
     }

     void LuuFileNL(ListNL &lnl){
        FILE*f;
        f = fopen("NguyenLieu","wb");
        for( NodeNL *p = lnl.nlHead; p != NULL; p = p ->nlnext){
            fwrite (&p ->infoNL, sizeof(NL),1,f);
        }
        fclose(f);
        cout<<"\n\tDa luu File!";

    }

    void DocFileNL(ListNL &lnl){
            initNL(lnl);
            FILE*f;
            NL nl;
            f = fopen("NguyenLieu","rb");
            while(true) {
                fread (&nl,sizeof(NL),1,f);
                if(feof(f)) break;
                chencuoiNL(lnl, createNodeNL(nl));
            }
            fclose(f);
            cout<<"\nDanh sach Nguyen Lieu trong File la: ";
            outputlistNL(lnl);
    }

	void xoaNLdau(ListNL &lnl){
	    NodeNL *p;
	    if(lnl.nlHead != NULL ){
            p = lnl.nlHead;
            lnl.nlHead = lnl.nlHead ->nlnext;
            lnl.nlHead ->nlprev = NULL;
            delete p;
            if(lnl.nlHead == NULL)  lnl.nlTail = NULL;
	    }
	}

	void xoaNLcuoi(ListNL &lnl){
         NodeNL *p;
         if(lnl.nlTail != NULL){
            p = lnl.nlTail;
            lnl.nlTail = lnl.nlTail ->nlprev;
            lnl.nlTail ->nlnext = NULL;
            delete p;
            if(lnl.nlHead == NULL )  lnl.nlTail = NULL;
         }
	}

	void xoaNLcosoluongduoi5(ListNL &lnl){

	}


	void xoaNLmsaun(ListNL &lnl, NodeNL *n){
	    NodeNL *m;
	    if(n == NULL)  exit(1);
	    else {
            if( n == lnl.nlTail) exit(1);
                m = n ->nlnext;
                n ->nlnext = m ->nlnext;
                if( m == lnl.nlTail ) lnl.nlTail = n;
                else     m ->nlnext ->nlprev = n;
                delete m;
            }
	    }


	void xoaNLmtruocn(ListNL &lnl, NodeNL *n){
         NodeNL *m;
         if(n == NULL) exit(1);
         else {
            if(n == lnl.nlTail) exit(1);
            m = n ->nlprev;
            n ->nlprev = m ->nlprev;
            if(m == lnl.nlHead) lnl.nlHead = n;
            else         m ->nlprev ->nlnext = n;
            delete m;
         }
	}

    void xoamaNL(ListNL &lnl, int xoama){
        NodeNL *s;
        if(xoama == lnl.nlHead ->infoNL.maNL){
            NodeNL *xoama = lnl.nlHead;
            lnl.nlHead = lnl.nlHead ->nlnext;
            delete xoama;
        }
        else{
            NodeNL *p = lnl.nlHead;
            while(p != NULL){
                if(p ->infoNL.maNL == xoama){
                    s ->nlnext = p ->nlnext;
                    delete p;
                }
                s = p;
                p = p ->nlnext;
            }
        }
    }

    void xoatenNL(ListNL &lnl, char xoaten[]){
        NodeNL *s;
        if(xoaten == lnl.nlHead ->infoNL.tenNL){
            NodeNL *xoaten = lnl.nlHead;
            lnl.nlHead = lnl.nlHead ->nlnext;
            delete xoaten;
        }
        else{
            NodeNL *p = lnl.nlHead;
            while(p != NULL ){
                if(p ->infoNL.tenNL == xoaten){
                    s ->nlnext = p ->nlnext;
                    delete p;
                }
                s = p;
                p = p ->nlnext;
            }
        }
    }

    /*case 13:  cout<<"\nNhap ten nguyen lieu can xoa: "; cin>>xoaten;
                 xoatenNL(lnl, xoaten);
                 cout<<"\nDanh sach sau khi xoa la: ";
                 outputlistNL(lnl); */



	void Sortgiatangdan(ListNL &lnl){
         NL nl;
         NL temp;
         NodeNL *p;
         NodeNL *q;
         for(p = lnl.nlHead; p != lnl.nlTail; p = p ->nlnext ){
            for(q = p ->nlnext; q != NULL; q = q ->nlnext){
                if(p ->infoNL.giaNL > q ->infoNL.giaNL){
                         temp = p ->infoNL;
                         p ->infoNL = q ->infoNL;
                         q ->infoNL = temp;
                }
            }
         }
         cout<<"\nDanh sach Nguyen Lieu sau khi sxep Tang dan theo Gia: ";
         outputlistNL(lnl);
     }

     void Sortgiagiamdan(ListNL &lnl){
         NL nl;
         NL temp;
         NodeNL *p;
         NodeNL *q;
         for(p = lnl.nlHead; p != lnl.nlTail; p = p ->nlnext ){
            for(q = p ->nlnext; q != NULL; q = q ->nlnext){
                if(p ->infoNL.giaNL < q ->infoNL.giaNL){
                         temp = p ->infoNL;
                         p ->infoNL = q ->infoNL;
                         q ->infoNL = temp;
                }
            }
         }
         cout<<"\nDanh sach Nguyen Lieu sau khi sxep Giam dan theo Gia: ";
         outputlistNL(lnl);
     }

     void Sortsoluonggiamdan(ListNL &lnl){
         NL nl;
         NL temp;
         NodeNL *p;
         NodeNL *q;
         for(p = lnl.nlHead; p != lnl.nlTail; p = p ->nlnext ){
            for(q = p ->nlnext; q != NULL; q = q ->nlnext){
                if(p ->infoNL.soluongNL < q ->infoNL.soluongNL){
                         temp = p ->infoNL;
                         p ->infoNL = q ->infoNL;
                         q ->infoNL = temp;
                }
            }
         }
         cout<<"\nDanh sach Nguyen Lieu sau khi sxep Giam dan theo So Luong: ";
         outputlistNL(lnl);
     }

     void Sortsoluongtangdan(ListNL &lnl){
         NL nl;
         NL temp;
         NodeNL *p;
         NodeNL *q;
         for(p = lnl.nlHead; p != lnl.nlTail; p = p ->nlnext ){
            for(q = p ->nlnext; q != NULL; q = q ->nlnext){
                if(p ->infoNL.soluongNL > q ->infoNL.soluongNL){
                         temp = p ->infoNL;
                         p ->infoNL = q ->infoNL;
                         q ->infoNL = temp;
                }
            }
         }
         cout<<"\nDanh sach Nguyen Lieu sau khi sxep Tang dan theo So Luong: ";
         outputlistNL(lnl);
     }

     void SortTenNLtheoAlphabel(ListNL &lnl){
            NodeNL *p = lnl.nlHead;
            NodeNL *q;
            if( p != NULL ){
                while( p != NULL ){
                    q = p ->nlnext;
                    while( q != NULL ){
                        if( strcmp(p ->infoNL.tenNL, q ->infoNL.tenNL) > 0 ){
                            NL temp = p ->infoNL;
                            p ->infoNL = q ->infoNL;
                            q ->infoNL = temp;   // bubble sort
                        }
                        q = q ->nlnext;
                    }
                    p = p ->nlnext;
                }
                cout<<"\n Danh sach ten Nguyen lieu sap xep theo Alphabel: ";
                outputlistNL(lnl);
            }
            else {
                    cout<<"\n Khong co Gia tri nao trong danh sach!";
            }
     }

     void SortmaNLtangdan(ListNL &lnl){
         NL nl;
         NL temp;
         NodeNL *p;
         NodeNL *q;
         for(p = lnl.nlHead; p != lnl.nlTail; p = p ->nlnext ){
            for(q = p ->nlnext; q != NULL; q = q ->nlnext){
                if(p ->infoNL.maNL > q ->infoNL.maNL){
                         temp = p ->infoNL;
                         p ->infoNL = q ->infoNL;
                         q ->infoNL = temp;
                }
            }
         }
         cout<<"\nDanh sach Nguyen Lieu sau khi sxep Tang dan theo maNL: ";
         outputlistNL(lnl);
     }

     void SortmaNLgiamdan(ListNL &lnl){
         NL nl;
         NL temp;
         NodeNL *p;
         NodeNL *q;
         for(p = lnl.nlHead; p != lnl.nlTail; p = p ->nlnext ){
            for(q = p ->nlnext; q != NULL; q = q ->nlnext){
                if(p ->infoNL.maNL < q ->infoNL.maNL){
                         temp = p ->infoNL;
                         p ->infoNL = q ->infoNL;
                         q ->infoNL = temp;
                }
            }
         }
         cout<<"\nDanh sach Nguyen Lieu sau khi sxep Giam dan theo maNL: ";
         outputlistNL(lnl);
     }

     void timkiemtheomaNL(ListNL &lnl, int manlX){
        NodeNL *p = lnl.nlHead;
        while( p != NULL){
            if( p->infoNL.maNL == manlX){
               cout<<endl<<"maNL"<<setw(10)<<"tenNL"<<setw(15)<<"soluongNL"<<setw(15)<<"giaNL"<<setw(20)<<"nguonnhapNL"<<endl;
               cout<<endl<<p->infoNL.maNL<<setw(10)<<p->infoNL.tenNL<<setw(15)<<p->infoNL.soluongNL<<setw(15)<<p->infoNL.giaNL<<setw(20)<<p->infoNL.nguonnhapNL;
            }
            p=p->nlnext;
        }
    }

     /*void timkiemtheomaNL(ListNL &lnl){
          char maX[50];
          NodeNL * p = lnl.nlHead;
          cout<<"\nNhap ma Nguyen Lieu can tim: "; fflush(stdin); gets(maX);

          while( p != NULL ){
            if(strcmp(maX, p ->infoNL.maNL) == 0){
             cout<<endl<<p->infoNL.maNL<<setw(10)<<p->infoNL.tenNL<<setw(15)<<p->infoNL.soluongNL<<setw(15)<<p->infoNL.giaNL<<setw(20)<<p->infoNL.nguonnhapNL;
            }
            p = p ->nlnext;
          }
     }*/


    /*NodeNL *timkiemNLtheoma(ListNL &lnl, char manlX[])         // chen NL vao sau NL co ma x
        {
            for (NodeNL *p = lnl.nlHead; p != NULL; p = p->nlnext)
            {
                if (strcmp(p->infoNL.maNL, manlX) == 0)
                {
                    return p;
                }
            }
        }*/

     void timkiemtheotenNL(ListNL &lnl){
          char tennlX[50];
          NodeNL * p = lnl.nlHead;
          cout<<"\nNhap ten Nguyen Lieu can tim: "; fflush(stdin); gets(tennlX);

          while( p != NULL ){
            if(strcmp(tennlX, p ->infoNL.tenNL) == 0){
              cout<<endl<<p->infoNL.maNL<<setw(10)<<p->infoNL.tenNL<<setw(15)<<p->infoNL.soluongNL<<setw(15)<<p->infoNL.giaNL<<setw(20)<<p->infoNL.nguonnhapNL;
            }
            p = p ->nlnext;
          }
     }

     void themNLcomaX(ListNL &lnl, NodeNL *q, NL &nl){
            NodeNL * p;
            cout<<"\nNhap thong tin Nguyen lieu can them: "<<endl;
            input1(nl);
            p = createNodeNL(nl);
            if(q != NULL){
                p ->nlnext = q ->nlnext;
                q ->nlnext = p;
                if(q == lnl.nlTail)  lnl.nlTail = p;
            }
     }





     /*case 12:{

                            cout<<"\n12. Them nguyen lieu vao sau nguyen lieu co ma X";
                            char manlX[50];
                            cout<<"\nNhap ma nguyen lieu can tim: ";  fflush(stdin); gets(manlX);
                            p = timkiemNLtheoma(lnl, manlX);
                            if( p != NULL ){
                                cout<<"\nTim thay Nguyen lieu co maX";
                                themNLcomaX(lnl, p, nl);
                                outputlistNL(lnl);
                                cout<<endl<<"\n\tDanh sach sau khi them 1 NL vao sau 1 NL co ma X: "<<endl;
                            }
                            else cout<<"\n\tKo tim thay nguyen lieu";
                                break;
                }
                            break;*/



    int menuNL(){
        FILE *f;
        ListNL lnl;
        NodeNL *p;
        initNL(lnl);
        NL nl;
        int chonNL;
        int manlX;
        int xoama;
        do{
            cout<<"\n\t\tQuan ly Nguyen Lieu ";
            cout<<"\n1. Nhap danh sach Nguyen Lieu: ";
            cout<<"\n2. Hien danh sach Nguyen Lieu: ";
            cout<<"\n3. Luu File Nguyen Lieu";
            cout<<"\n4. Doc File Nguyen Lieu";
            cout<<"\n5. Them nguyen lieu vao Cuoi danh sach ";
            cout<<"\n6. Xoa 1 nguyen lieu theo Ma nguyen lieu ";
            cout<<"\n7. Sap xep ten nguyen lieu theo bang chu cai ";
            cout<<"\n8. Tim kiem nguyen lieu theo Ma ";




            cout<<"\n\tNhap lua chon cua ban: ";   cin>>chonNL;
            switch(chonNL){
                case 1: inputlistNL(lnl);
                            break;
                case 2: outputlistNL(lnl);
                            getch();
                            break;
                case 3:     LuuFileNL(lnl);
                            getch();
                            break;
                case 4:     DocFileNL(lnl);
                            getch();
                            break;
                case 5:
                         themNLcuoids(lnl);
                         cout<<"\nDanh sach Nguyen lieu sau khi them vao cuoi la: ";
                         outputlistNL(lnl);
                         getch();
                         break;
                case 6:
                     cout<<"\nNhap ma nguyen lieu can xoa: "; cin>>xoama;
                     xoamaNL(lnl, xoama);
                     cout<<"\nDanh sach sau khi xoa la: ";
                     outputlistNL(lnl);
                     getch();
                            break;
                case 7:     SortTenNLtheoAlphabel(lnl);
                            getch();
                            break;
                case 8:
                     cout<<"\nNhap ma NL can tim: "; cin>>manlX;
                     cout<<"\nThong tin nguyen lieu can tim la: ";
                     timkiemtheomaNL(lnl, manlX);
                     getch();
                            break;

                default: cout<<"\nNhap lai: ";
            }
        }while( chonNL != 0);
    }

        //Sản Phẩm
    struct SP{
        int maSP;
        char tenSP[50];
        float giaSP;
    };

    struct NodeSP{
        SP infoSP;
        struct NodeSP *spnext;
        struct NodeSP *spprev;
    };

    struct ListSP{
        NodeSP *spHead;
        NodeSP *spTail;
    };

    void initSP(ListSP &lsp){
        lsp.spHead = lsp.spTail = NULL;
    }

    NodeSP *createNodeSP(SP sp){
        NodeSP *s = new NodeSP;
        if(s == NULL) exit(1);
        s ->infoSP = sp;
        s ->spnext = NULL;
        s ->spprev = NULL;
        return s;
    }

    void input2(SP &sp){
        cout<<"\nNhap ma san pham: ";
        cin>>sp.maSP;
        cout<<"\nNhap ten san pham: ";
        fflush(stdin); gets(sp.tenSP);
        cout<<"\nNhap gia san pham: ";
        cin>>sp.giaSP;
        cout<<endl;
    }

    void output2(SP sp){
        cout<<endl<<sp.maSP<<setw(15)<<sp.tenSP<<setw(20)<<sp.giaSP;
        cout<<endl;
    }

     void chendauSP(ListSP &lsp, NodeSP *s){
        if(lsp.spHead == NULL ){
            lsp.spHead = lsp.spTail = s;
        }
        else {
            s ->spnext = lsp.spHead;
            lsp.spHead ->spprev = s;
            lsp.spHead = s;
        }
    }

    void chencuoiSP(ListSP &lsp, NodeSP *s){
        if(lsp.spHead == NULL ){
            lsp.spHead = lsp.spTail = s;
        }
        else {
            lsp.spTail ->spnext = s;
            s ->spprev = lsp.spTail;
            lsp.spTail = s;
        }
    }

    void inputlistSP(ListSP &lsp){
        int n;
        SP sp;
        cout<<"\nNhap so luong mat hang: "; cin>>n;
        for(int i = 1; i <= n; i++){
            input2(sp);
            NodeSP *s = createNodeSP(sp);
            chencuoiSP(lsp, s);
        }
    }

    void outputlistSP(ListSP lsp){
        cout<<"\nDanh sach San Pham la: ";
        cout<<endl<<"maSP"<<setw(15)<<"tenSP"<<setw(20)<<"giaSP";
        for(NodeSP *s = lsp.spHead; s != NULL; s = s ->spnext){
            output2(s ->infoSP);
        }
    }

    void LuuFileSP(ListSP &lsp){
        FILE*f;
        f = fopen("SanPham","wb");
        for( NodeSP *s = lsp.spHead; s != NULL; s = s ->spnext){
            fwrite (&s ->infoSP, sizeof(SP),1,f);
        }
        fclose(f);
        cout<<"\n\tDa luu File!";
    }

    void DocFileSP(ListSP &lsp){
            initSP(lsp);
            FILE*f;
            SP sp;
            f = fopen("SanPham","rb");
            while(true) {
                fread (&sp,sizeof(SP),1,f);
                if(feof(f))break;
                chencuoiSP(lsp, createNodeSP(sp));
            }
            fclose(f);
            outputlistSP(lsp);
    }

    void themSPdauds(ListSP &lsp){
          SP sp;
          cout<<"\nNhap thong tin San Pham can them: ";
          cout<<endl;
          input2(sp);
          NodeSP *s = createNodeSP(sp);
          chendauSP(lsp, s);
          cout<<endl;
    }

    void themSPcuoids(ListSP &lsp){
          SP sp;
          cout<<"\nNhap thong tin San Pham can them: ";
          cout<<endl;
          input2(sp);
          NodeSP *s = createNodeSP(sp);
          chencuoiSP(lsp, s);
          cout<<endl;
    }

    void SortTenSPtheoAlphabel(ListSP &lsp){
            NodeSP *s = lsp.spHead;
            NodeSP *d;
            if( s != NULL ){
                while( s != NULL ){
                    d = s ->spnext;
                    while( d != NULL ){
                        if( strcmp(s ->infoSP.tenSP , d ->infoSP.tenSP) > 0 ){
                            SP temp = s ->infoSP;
                            s ->infoSP = d ->infoSP;
                            d ->infoSP = temp;   // bubble sort
                        }
                        d = d ->spnext;
                    }
                    s = s ->spnext;
                }
                cout<<"\n Danh sach ten San Pham sap xep theo Alphabel: ";
                outputlistSP(lsp);
            }
            else {
                    cout<<"\n Khong co Gia tri nao trong danh sach!";
            }
     }


     void timkiemtheotenSP(ListSP &lsp){
          char tenspX[50];
          NodeSP * s = lsp.spHead;
          cout<<"\nNhap ten San Pham can tim: "; fflush(stdin); gets(tenspX);

          while( s != NULL ){
            if(strcmp(tenspX, s ->infoSP.tenSP) == 0){
              cout<<endl<<s->infoSP.maSP<<setw(15)<<s->infoSP.tenSP<<setw(20)<<s->infoSP.giaSP;
            }
            s = s ->spnext;
          }
     }

     void xoaSPdau(ListSP &lsp){
	    NodeSP *s;
	    if(lsp.spHead != NULL ){
            s = lsp.spHead;
            lsp.spHead = lsp.spHead ->spnext;
            lsp.spHead ->spprev = NULL;
            delete s;
            if(lsp.spHead == NULL)  lsp.spTail = NULL;
	    }
	}

     void xoaSPcuoi(ListSP &lsp){
         NodeSP *s;
         if(lsp.spTail != NULL){
            s = lsp.spTail;
            lsp.spTail = lsp.spTail ->spprev;
            lsp.spTail ->spnext = NULL;
            delete s;
            if(lsp.spHead == NULL )  lsp.spTail = NULL;
         }
	}

	void xoamaSP(ListSP &lsp, int xoamasp){
        NodeSP *g;
        if(xoamasp == lsp.spHead ->infoSP.maSP){
            NodeSP *xoamasp = lsp.spHead;
            lsp.spHead = lsp.spHead ->spnext;
            delete xoamasp;
        }
        else{
            NodeSP *s = lsp.spHead;
            while(s != NULL){
                if(s ->infoSP.maSP == xoamasp){
                    g ->spnext = s ->spnext;
                    delete s;
                }
                g = s;
                s = s ->spnext;
            }
        }
    }

    void Sortgiatangdan(ListSP &lsp){
         SP sp;
         SP temp;
         NodeSP *s;
         NodeSP *d;
         for(s = lsp.spHead; s != lsp.spTail; s = s ->spnext ){
            for(d = s ->spnext; d != NULL; s = s ->spnext){
                if(s ->infoSP.giaSP > d ->infoSP.giaSP){
                         temp = s ->infoSP;
                         s ->infoSP = d ->infoSP;
                         d ->infoSP = temp;
                }
            }
         }
         cout<<"\nDanh sach san pham sau khi sxep Tang dan theo Gia: ";
         outputlistSP(lsp);
     }

     void Sortgiagiamdan(ListSP &lsp){
         SP sp;
         SP temp;
         NodeSP *s;
         NodeSP *d;
         for(s = lsp.spHead; s != lsp.spTail; s = s ->spnext ){
            for(d = s ->spnext; d != NULL; d = d ->spnext){
                if(s ->infoSP.giaSP < d ->infoSP.giaSP){
                         temp = s ->infoSP;
                         s ->infoSP = d ->infoSP;
                         d ->infoSP = temp;
                }
            }
         }
         cout<<"\nDanh sach san pham sau khi sxep Giam dan theo Gia: ";
         outputlistSP(lsp);
     }

     /*void Sortsoluonggiamdan(ListSP &lsp){
         SP sp;
         SP temp;
         NodeSP *s;
         NodeSP *d;
         for(s = lsp.spHead; s != lsp.spTail; s = s ->spnext ){
            for(d = s ->spnext; d != NULL; d = d ->spnext){
                if(s ->infoSP.soluong < d ->infoSP.soluong){
                         temp = s ->infoSP;
                         s ->infoSP = d ->infoSP;
                         d ->infoSP = temp;
                }
            }
         }
         cout<<"\nDanh sach san pham sau khi sxep Giam dan theo So Luong: ";
         outputlistSP(lsp);
     }

     void Sortsoluongtangdan(ListSP &lsp){
         SP sp;
         SP temp;
         NodeSP *s;
         NodeSP *d;
         for(s = lsp.spHead; s != lsp.spTail; s = s ->spnext ){
            for(d = s ->spnext; d != NULL; d = d ->spnext){
                if(s ->infoSP.soluong > d ->infoSP.soluong){
                         temp = s ->infoSP;
                         s ->infoSP = d ->infoSP;
                         d ->infoSP = temp;
                }
            }
         }
         cout<<"\nDanh sach san pham sau khi sxep Tang dan theo So Luong: ";
         outputlistSP(lsp);
     }

     void listSPsoluongtren10(ListSP &lsp){       // thong ke
         int dem = 0;
         for(NodeSP *s = lsp.spHead; s != NULL; s = s ->spnext){
            if(s ->infoSP.soluong > 10){
                output2(s ->infoSP);
                dem++;
            }
            else    cout<<"\nKhong co san pham nao!";
        }
     }
    */

    void thongkeSPgiatren100(ListSP &lsp){
         int dem = 0;
         for(NodeSP *s = lsp.spHead; s != NULL; s = s ->spnext){
            if(s ->infoSP.giaSP > 100){
                output2(s ->infoSP);
                dem++;
            }
             else      cout<<"\nKhong co san pham nao!";
        }
    }

     void timSPcogiacaonhat(ListSP &lsp){
         NodeSP *giamax;
         giamax = lsp.spHead;
         for(NodeSP *s = lsp.spHead; s != NULL; s = s ->spnext){
            if(s ->infoSP.giaSP > giamax ->infoSP.giaSP){
                giamax = s;
            }
         }
         cout<<"\n San pham co gia cao nhat: ";
         cout<<endl<<"maSP"<<setw(15)<<"tenSP"<<setw(20)<<"giaSP";
	     cout<<giamax->infoSP.maSP<<setw(15)<<giamax->infoSP.tenSP<<setw(12)<<giamax->infoSP.giaSP;
     }

     void timSPcogiathapnhat(ListSP &lsp){
         NodeSP *giamin;
         giamin = lsp.spHead;
         for(NodeSP *s = lsp.spHead; s != NULL; s = s ->spnext){
            if(s ->infoSP.giaSP < giamin ->infoSP.giaSP){
                giamin = s;
            }
         }
         cout<<"\n San pham co gia thap nhat: ";
         cout<<endl<<"maSP"<<setw(15)<<"tenSP"<<setw(20)<<"giaSP";
	     cout<<giamin->infoSP.maSP<<setw(15)<<giamin->infoSP.tenSP<<setw(20)<<giamin->infoSP.giaSP;
     }

     /*void timkiemtheomaSP(ListSP &lsp){
          char maspX[50];                           // Ma kieu char
          NodeSP * s = lsp.spHead;
          cout<<"\nNhap ma San Pham can tim: "; fflush(stdin); gets(maspX);

          while( s != NULL ){
            if(strcmp(maspX, s ->infoSP.maSP) == 0){
              cout<<endl<<s->infoSP.maSP<<setw(15)<<s->infoSP.tenSP<<setw(20)<<s->infoSP.giaSP;
            }
            s = s ->spnext;
          }
     }*/

     void timkiemtheomaSP(ListSP &lsp, int maspx){
        NodeSP *s = lsp.spHead;
        while( s != NULL){
            if( s->infoSP.maSP == maspx){
               cout<<endl<<"maSP"<<setw(15)<<"tenSP"<<setw(20)<<"giaSP"<<endl;
               cout<<endl<<s->infoSP.maSP<<setw(15)<<s->infoSP.tenSP<<setw(20)<<s->infoSP.giaSP;
            }
            s = s ->spnext;
        }
    }



     /*NodeNL *timkiemSPtheoma(ListSP &lsp, char maspX[]){                   // chen SP vao sau SP co ma x
            for (NodeNL *p = lnl.nlHead; p != NULL; p = p->nlnext)
            {
                if (strcmp(p->infoNL.maNL, maX) == 0)
                {
                    return p;
                }
            }
    }*/

    /*void themSPcomaX(ListSP &lsp, NodeSP *d, SP &sp){
            NodeSP * s;
            cout<<"\nNhap thong tin San Pham can them: "<<endl;
            input2(sp);
            s = createNodeSP(sp);
            if(d != NULL){
                s ->spnext = d->spnext;
                d ->spnext = s;
                if(d == lsp.spTail)  lsp.spTail = s;
            }
     }

    case 12:
            {    cout<<"\n12. Them san pham vao sau san pham co ma X";
                            char maspX[50];
                            cout<<"\nNhap ma san pham can tim: ";  fflush(stdin); gets(maspX);
                            p = timkiemSPtheoma(lsp, maspX);
                            if( p != NULL ){
                                cout<<"\nTim thay San Pham co maX";
                                themNLcomaX(lnl, p, nl);
                                outputlistNL(lnl);
                                cout<<endl<<"\n\tDanh sach sau khi them 1 NL vao sau 1 NL co ma X: "<<endl;
                            }
                            else cout<<"\n\tKo tim thay San Pham";
                                break;
            }
                            break;*/


    int menuSP(){
        FILE *f;
        SP sp;
        ListSP lsp;
        NodeSP *s;
        initSP(lsp);
        int chonSP;
        int maspx, xoamasp;

        do{
            cout<<"\n\t\tQuan Li San Pham ";
            cout<<"\n1. Nhap danh sach San Pham ";
            cout<<"\n2. Hien danh sach San Pham ";
            cout<<"\n3. Luu File San Pham";
            cout<<"\n4. Hien File San Pham";
            cout<<"\n5. Them 1 san pham vao cuoi danh sach";
            cout<<"\n6. Xoa 1 san pham theo Ma san pham";
            cout<<"\n7. Sap xep danh sach ten SP theo thu tu bang chu cai";
            cout<<"\n8. Tim San Pham theo ma: ";
            //cout<<"\n9.Thong ke san pham co gia tren 100";

            cout<<"\n\tNhap lua chon cua ban: ";
            cin>>chonSP;

            switch(chonSP){
                case 1: inputlistSP(lsp);
                    break;
                case 2: outputlistSP(lsp);
                    getch();
                    break;
                case 3: LuuFileSP(lsp);
                    getch();
                    break;
                case 4: DocFileSP(lsp);
                    getch();
                    break;
                case 5:
                        themSPcuoids(lsp);
                        cout<<"\nDanh sach san pham sau khi them vao cuoi la: ";
                        outputlistSP(lsp);
                        getch();
                    break;
                case 6:
                        cout<<"\nNhap ma san pham can xoa: "; cin>>xoamasp;
                        xoamaSP(lsp, xoamasp);
                        cout<<"\n\tDa Xoa!";
                        cout<<"\nDanh sach san pham sau khi xoa la: ";
                        outputlistSP(lsp);
                        getch();
                    break;
                case 7:  SortTenSPtheoAlphabel(lsp);
                    getch();
                    break;
                case 8:
                    cout<<"\nNhap ma san pham can tim: "; cin>>maspx;
                    timkiemtheomaSP(lsp, maspx);
                    getch();
                    break;

                default: cout<<"\Nhap lai: ";
            }
        }while( chonSP != 0);
    }

     // Hóa Đơn
        struct HD{
            int maHD;
            char TenSPB[50];
            float GiaSPB;
            int SoLuongSPB;
            char NgayBanHD[50];
            long double thanhtien;
        };

        struct NodeHD{
            HD infoHD;
            struct NodeHD *hdnext;
            struct NodeHD *hdprev;
        };

        struct ListHD{
            NodeHD *hdHead;
            NodeHD *hdTail;
        };

        void initHD(ListHD &lhd){
            lhd.hdHead = lhd.hdTail = NULL;
        }

        NodeHD *createNodeHD(HD hd){
            NodeHD *h = new NodeHD;
            if( h == NULL) exit(1);
            h ->infoHD = hd;
            h ->hdnext = NULL;
            h ->hdprev = NULL;
            return h;
        }

        void chendauHD(ListHD &lhd, NodeHD *h){
            if(lhd.hdHead == NULL ){
            lhd.hdHead = lhd.hdTail = h;
            }
            else {
            h ->hdnext = lhd.hdHead;
            lhd.hdHead ->hdprev = h;
            lhd.hdHead = h;
            }
        }

        void chencuoiHD(ListHD &lhd, NodeHD *h){
             if(lhd.hdHead == NULL ){
             lhd.hdHead = lhd.hdTail = h;
            }
            else {
            lhd.hdTail ->hdnext = h;
            h ->hdprev = lhd.hdTail;
            lhd.hdTail = h;
            }
        }

        void input3(HD &hd){
            cout<<"\nNhap ma hoa don: "; cin>>hd.maHD;
            cout<<"\nNhap ten san pham ban: "; fflush(stdin); gets(hd.TenSPB);
            cout<<"\nNhap gia san pham ban: "; cin>>hd.GiaSPB;
            cout<<"\nNhap so luong san pham ban: "; cin>>hd.SoLuongSPB;
            cout<<"\nNhap ngay ban san pham: ";  fflush(stdin); gets(hd.NgayBanHD);
            hd.thanhtien = hd.GiaSPB * hd.SoLuongSPB;
            cout<<endl;
        }

        void output3(HD hd){
            cout<<hd.maHD<<setw(20)<<hd.TenSPB<<setw(15)<<hd.GiaSPB<<setw(20)<<hd.SoLuongSPB<<setw(15)<<hd.NgayBanHD<<setw(20)<<hd.thanhtien;
            cout<<endl;
        }

        void inputlistHD(ListHD &lhd){
            int slhd;
            HD hd;
            cout<<"\nNhap so luong hoa don: "; cin>>slhd;
            for(int i = 1; i <= slhd; i++){
                input3(hd);
                NodeHD *h = createNodeHD(hd);
                chencuoiHD(lhd, h);
            }
        }

        void outputlistHD(ListHD lhd){
            cout<<"\nDanh sach hoa don la: "<<endl;
            cout<<"maHD"<<setw(20)<<"TenSPB"<<setw(15)<<"GiaSPB"<<setw(20)<<"SoLuongSPB"<<setw(15)<<"NgayBanHD"<<setw(20)<<"thanhtienSP";
            cout<<endl;
            for(NodeHD *h = lhd.hdHead; h != NULL; h = h ->hdnext){
                output3(h ->infoHD);
            }
        }

        void themHDdauds(ListHD &lhd){
          HD hd;
          cout<<"\nNhap thong tin Hoa Don can them: ";
          cout<<endl;
          input3(hd);
          NodeHD *h = createNodeHD(hd);
          chendauHD(lhd, h);
          cout<<endl;
        }

        void themHDcuoids(ListHD &lhd){
          HD hd;
          cout<<"\nNhap thong tin Hoa Don can them: ";
          cout<<endl;
          input3(hd);
          NodeHD *h = createNodeHD(hd);
          chencuoiHD(lhd, h);
          cout<<endl;
        }

        void LuuFileHD(ListHD &lhd){
        FILE*f;
        f = fopen("HoaDon","wb");
        for( NodeHD *h = lhd.hdHead; h != NULL; h = h ->hdnext){
            fwrite (&h ->infoHD, sizeof(HD),1,f);
        }
        fclose(f);
        cout<<"\n\tDa luu File!";

        }

        void DocFileHD(ListHD &lhd){
            initHD(lhd);
            FILE*f;
            HD hd;
            f = fopen("HoaDon","rb");
            while(true) {
                fread (&hd,sizeof(HD),1,f);
                if(feof(f)) break;
                chencuoiHD(lhd, createNodeHD(hd));
            }
            fclose(f);
            cout<<"\nDanh sach Hoa Don trong File la: ";
            outputlistHD(lhd);
        }

        void Sortsoluonggiamdan(ListHD &lhd){
         HD hd;
         HD temp;           // s = h        d = t
         NodeHD *h;
         NodeHD *t;
         for(h = lhd.hdHead; h != lhd.hdTail; h = h ->hdnext ){
            for(t = h ->hdnext; t != NULL; t = t ->hdnext){
                if(h ->infoHD.SoLuongSPB < t ->infoHD.SoLuongSPB){
                         temp = h ->infoHD;
                         h ->infoHD = t ->infoHD;
                         t ->infoHD = temp;
                }
            }
         }
         cout<<"\nDanh sach HoaDon sau khi sxep Giam dan theo So Luong: ";
         outputlistHD(lhd);
        }

        void Sortsoluongtangdan(ListHD &lhd){
         HD hd;
         HD temp;
         NodeHD *h;
         NodeHD *t;
         for(h = lhd.hdHead; h != lhd.hdTail; h = h ->hdnext ){
            for(t = h ->hdnext; t != NULL; t = t ->hdnext){
                if(h ->infoHD.SoLuongSPB > t ->infoHD.SoLuongSPB){
                         temp = h ->infoHD;
                         h ->infoHD = t ->infoHD;
                         t ->infoHD = temp;
                }
            }
         }
         cout<<"\nDanh sach HoaDon sau khi sxep Tang dan theo So Luong: ";
         outputlistHD(lhd);
        }

        void SortmaHDtangdan(ListHD &lhd){
         HD hd;
         HD temp;
         NodeHD *h;
         NodeHD *t;
         for(h = lhd.hdHead; h != lhd.hdTail; h = h ->hdnext ){
            for(t = h ->hdnext; t != NULL; t = t ->hdnext){
                if(h ->infoHD.maHD > t ->infoHD.maHD){
                         temp = h ->infoHD;
                         h ->infoHD = t ->infoHD;
                         t ->infoHD = temp;
                }
            }
         }
         cout<<"\nDanh sach HoaDon sau khi sxep Tang dan theo MaHD la: ";
         outputlistHD(lhd);
        }

        void SortmaHDgiamdan(ListHD &lhd){
         HD hd;
         HD temp;
         NodeHD *h;
         NodeHD *t;
         for(h = lhd.hdHead; h != lhd.hdTail; h = h ->hdnext ){
            for(t = h ->hdnext; t != NULL; t = t ->hdnext){
                if(h ->infoHD.maHD < t ->infoHD.maHD){
                         temp = h ->infoHD;
                         h ->infoHD = t ->infoHD;
                         t ->infoHD = temp;
                }
            }
         }
         cout<<"\nDanh sach HoaDon sau khi sxep Giam dan theo MaHD la: ";
         outputlistHD(lhd);
        }

        void timkiemtheomaHD(ListHD &lhd, int mahdX){
        NodeHD *h = lhd.hdHead;
        while( h != NULL){
            if( h->infoHD.maHD == mahdX){
               cout<<"maHD"<<setw(20)<<"TenSPB"<<setw(15)<<"GiaSPB"<<setw(20)<<"SoLuongSPB"<<setw(15)<<"NgayBanHD"<<setw(20)<<"thanhtienSP";
               cout<<endl<<h->infoHD.maHD<<setw(20)<<h->infoHD.TenSPB<<setw(15)<<h->infoHD.GiaSPB<<setw(20)<<h->infoHD.SoLuongSPB<<setw(15)<<h->infoHD.NgayBanHD<<setw(20)<<h->infoHD.thanhtien;
             }
            h = h ->hdnext;
            }
        }

        void xoaHDdau(ListHD &lhd){
	    NodeHD *h;
                if(lhd.hdHead != NULL ){
                h = lhd.hdHead;
                lhd.hdHead = lhd.hdHead ->hdnext;
                lhd.hdHead ->hdprev = NULL;
                delete h;
                if(lhd.hdHead == NULL)  lhd.hdTail = NULL;
            }
        }

        void xoaHDcuoi(ListHD &lhd){
                NodeHD *h;
                if(lhd.hdTail != NULL){
                h = lhd.hdTail;
                lhd.hdTail = lhd.hdTail ->hdprev;
                lhd.hdTail ->hdnext = NULL;
                delete h;
                if(lhd.hdHead == NULL )  lhd.hdTail = NULL;
             }
        }

        void timSPBcothanhtienthapnhat(ListHD &lhd){
             NodeHD *thanhtienmin;
             thanhtienmin = lhd.hdHead;
             for(NodeHD *h = lhd.hdHead; h != NULL; h = h ->hdnext){
                if(h ->infoHD.thanhtien < thanhtienmin ->infoHD.thanhtien){
                    thanhtienmin = h;
                }
             }
             cout<<"\n San pham ban co ThanhTien thap nhat: ";
             cout<<"maHD"<<setw(20)<<"TenSPB"<<setw(15)<<"GiaSPB"<<setw(20)<<"SoLuongSPB"<<setw(15)<<"NgayBanHD"<<setw(20)<<"thanhtienSP";
             cout<<thanhtienmin->infoHD.maHD<<setw(20)<<thanhtienmin->infoHD.TenSPB<<setw(15)<<thanhtienmin->infoHD.GiaSPB<<setw(20)<<thanhtienmin->infoHD.SoLuongSPB<<setw(15)<<thanhtienmin ->infoHD.NgayBanHD<<setw(20)<<thanhtienmin ->infoHD.thanhtien;
         }

         void timSPBcothanhtiencaonhat(ListHD &lhd){
             NodeHD *thanhtienmax;
             thanhtienmax = lhd.hdHead;
             for(NodeHD *h = lhd.hdHead; h != NULL; h = h ->hdnext){
                if(h ->infoHD.thanhtien > thanhtienmax ->infoHD.thanhtien){
                    thanhtienmax = h;
                }
             }
             cout<<"\n San pham ban co ThanhTien cao nhat: ";
             cout<<"maHD"<<setw(20)<<"TenSPB"<<setw(15)<<"GiaSPB"<<setw(20)<<"SoLuongSPB"<<setw(15)<<"NgayBanHD"<<setw(20)<<"thanhtienSP";
             cout<<thanhtienmax->infoHD.maHD<<setw(20)<<thanhtienmax->infoHD.TenSPB<<setw(15)<<thanhtienmax->infoHD.GiaSPB<<setw(20)<<thanhtienmax->infoHD.SoLuongSPB<<setw(15)<<thanhtienmax ->infoHD.NgayBanHD<<setw(20)<<thanhtienmax ->infoHD.thanhtien;
         }

         void TongThanhTien(ListHD &lhd, NodeHD *h){
             float tongtien = 0;
             for(NodeHD *h = lhd.hdHead; h != NULL; h = h ->hdnext){
                tongtien = tongtien + h ->infoHD.thanhtien;
             }
             cout<<"\n\tTong tien cac san pham ban tren 1 hoa don la: "<<(double)tongtien;
         }

         void xoamaHD(ListHD &lhd, int xoamahd){
            NodeHD *s;
            if(xoamahd == lhd.hdHead ->infoHD.maHD){
                NodeHD *xoamahd = lhd.hdHead;
                lhd.hdHead = lhd.hdHead ->hdnext;
                delete xoamahd;
            }
            else{
                NodeHD *h = lhd.hdHead;
                while(h != NULL){
                    if(h ->infoHD.maHD == xoamahd){
                        s ->hdnext = h ->hdnext;
                        delete h;
                    }
                    s = h;
                    h = h ->hdnext;
                }
            }
        }

        int menuHD(){
            FILE *f;
            ListHD lhd;
            NodeHD *h;
            initHD(lhd);
            int chonHD;
            int mahdX, xoamahd;
            do {
                cout<<"\n\t\tQuan li Hoa Don ";
                cout<<"\n1. Nhap danh sach hoa don";
                cout<<"\n2. Hien danh sach hoa don";
                cout<<"\n3. Luu File Hoa Don";
                cout<<"\n4. Doc File Hoa Don";
                cout<<"\n5. Them 1 hoa don ";
                cout<<"\n6. Sap xep ds Hoa Don theo thu tu tang dan MaHD";
                cout<<"\n7. Xoa 1 Hoa don theo MaHD";
                cout<<"\n8. Tinh tong tien cac HoaDon";
                cout<<"\n9. Tim 1 Hoa Don theo MaHD";


                cout<<"\n\tNhap lua chon cua ban: "; cin>>chonHD;
                switch(chonHD){
                    case 1: inputlistHD(lhd);
                        break;
                    case 2: outputlistHD(lhd);
                        getch();
                        break;
                    case 3: LuuFileHD(lhd);
                        getch();
                        break;
                    case 4: DocFileHD(lhd);
                        getch();
                        break;
                    case 5: themHDcuoids(lhd);
                        getch();
                        break;
                    case 6: SortmaHDtangdan(lhd);
                        getch();
                        break;
                    case 7:
                        cout<<"\nNhap ma Hoa Don can xoa: "; cin>>xoamahd;
                        xoamaHD(lhd, xoamahd);
                        cout<<"\n\tDa Xoa!!!";
                        cout<<"\nDanh sach hoa don sau khi xoa la: ";
                        outputlistHD(lhd);
                        getch();
                        break;
                    case 8:
                        TongThanhTien(lhd, h);
                        getch();
                        break;
                    case 9:
                        cout<<"\nNhap ma Hoa Don can tim: "; cin>>mahdX;
                        timkiemtheomaHD(lhd, mahdX);
                        getch();
                        break;

                    default: cout<<"\nNhap lai: ";
                }
            }while(chonHD != 0);
        }

        int main(){
            int chonmain;
            do{
                cout<<"\n\t\t\tQUAN LI BAN HANG TAI CUA HANG BAN CAFE";
                cout<<"\n\t\t1. Quan li Nguyen Lieu";
                cout<<"\n\t\t2. Quan li San Pham";
                cout<<"\n\t\t3. Quan li Hoa Don";
                cout<<"\n\t\t0. Thoat";

                cout<<"\n\tNhap doi tuong ban muon quan li: "; cin>>chonmain;
                switch(chonmain){
                    case 0: break;

                    case 1: menuNL();
                            getch();
                            break;
                    case 2: menuSP();
                            getch();
                            break;
                    case 3: menuHD();
                            getch();
                            break;


                    default: {
                    system("cls");
                    cout<<"\n Lua chon khong hop le. Vui long chon lai!";
                    break;
                  }
                }
            }while(chonmain != 0);
            return 0;
            getch();
        }

