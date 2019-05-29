#include <stdio.h>
#include <windows.h>


//declare modular yang di bawah int main dan declare variabel
void loading(); void menu(); int timeCheck(); int errorHandling(); int sumChecker(); int saverChecker(); int slipgaji();int sumAkhir();
int input=0,backing=0, denda=0,counterHari=1,counterMinggu=1,sum=0, saver=0, saver1=0, saver2=0, saver3=0, saver4=0, i , j=0, k;
int minggu1[8]={0,0,0,0,0,0,0,0}; //array awal waktu yg kepake tiap minggu
int minggu2[8]={0,0,0,0,0,0,0,0};
int minggu3[8]={0,0,0,0,0,0,0,0};
int minggu4[8]={0,0,0,0,0,0,0,0};
int pass[2]={1806200186, 1806200002}; //array pass
char name[2][100]={"Edwiansyah Zaky", "Suryanegara"}; //arr nama

int main(){
  int switcher;
  loading(); //tipe TULISAN(); kek gini tuh modular, ini manggil modular transisi yg loading
  int nip;

  if(backing==0){ //backing tuh buat ngecek udh pernah masukan input bener atau tidak

    FILE *foto; //buka file luar
    foto = fopen("backdrop.txt","r");
    while(1){
      int w=fgetc(foto);
      if(w==EOF){
        break;
      }
      else{
        printf("%c", w); //ngeprint foto dari luar
      }
    }
    fclose(foto); // nutup file dri luar, trus msk ke progrram lagi
    system("pause");
    system("cls");
    loading();
    printf("*id default=0*\n");
    printf("Masukan Nomor Induk Pegawai : ");
    scanf("%d", &nip); //scan pass

    for(j=0;j<=2;j++){ //klo sama bakal nyimpen passnya tuh di posisi mana
    	if(pass[j]==nip){
    		k=j;
        goto start; // klo sama bakal langsung loncat
      }
    }
    errorHandling(); //klo gada yg sama bakal masuk modular ini, modular errorHandling trus otomatis balik ke awal
    start:
    loading();
    backing++; //klo dan sama bakal ngaish nilai backing +1 biar pas looping ke awal gauash masuk login
  }

  system("cls");
  printf("Halo saudara %s! Silahkan masukan pilihan yang anda inginkan\n", name[k]);
  menu(); //modular nampilin menu

  scanf("%d", &switcher); //scan angka buat masuk ke case mana/pilihan mana


  switch(switcher){

    case 0:{ //pilihan no
      if(counterHari%7==0){ //hari yg bisa sisa bagi 7 tuh 0 (kek 7,14,21), dia bakal loncat ke case 2
        goto casis;
      }
      else{
        counterHari++; //pindahh hari biasa aja
        main(); //balik ke menu awal
      }
      break;
    }

    case 1:{
      loading();
      timeCheck(); // modular ngecek input
      printf("\nJika anda sudah sepenuhnya menginput jam kerja pada hari ini,\npilih [1] untuk untuk ke menu awal : ");
      scanf("%d", &input); //nanyain klo mau balik ke menu hrs ngasih nilai 1, klo ga 1 bakal errorHandling
      if(input==1){
        main();
        backing++;
      }
      break;
    }

    case 2:{
      casis: //batu loncat dri case 0 tadi
      loading();
      sumChecker(); // modular ngerekap data pada hari itu dan minggu itu (doang)
      printf("Banyak waktu anda bekerja hari ini adalah %d jam %d menit\n", sum/60, sum%60); //sum hari itu, saver minggu itu
      printf("Banyak waktu anda bekerja minggu ini adalah %d jam %d menit\n", saver/60, saver%60);
      printf("-----------------------------------------------------------------");
      if(saver<2400){
        printf("\nSisa waktu kerja yang perlu anda penuhi pada minggu ini adalah %d jam %d menit\n", (2400-saver)/60, (2400-saver)%60);
      }
      else{
        printf("\nAnda telah memenuhi kuota jam kerja minggu ini\n");
      }
      printf("-----------------------------------------------------------------\n");

      if(counterMinggu==1){ // rekapan terakhir bakal disimpen di saver masing2
        saver1=saver;
      }
      else if(counterMinggu==2){
        saver2=saver;
      }
      else if(counterMinggu==3){
        saver3=saver;
      }
      else{
        saver4=saver;
      }

      saverChecker(saver1, 1); //bakal dicek sama modular ini klo minggu tersebut tuh udh terpenuhi atau belumnya
      saverChecker(saver2, 2);
      saverChecker(saver3, 3);
      saverChecker(saver4, 4);

      printf("\n\nMinggu ke-%d\n", counterMinggu);
      printf("\n\nPilih [1] untuk kembali ke menu awal\n");
      scanf("%d", &input);
      saver=0; //reset jam kerja di hari itu, klo mau manggil gampang soalnya udh disimpoen di array
      if(input==1){ //bakal minta 1 klo mau balik ke menu
        if(counterHari%7==0){ //kondisi dimana klo dia lgi hari 7 14 21, bakal balik ke menunya tuh nambahin minggu jg
          counterHari++; //nambah hari
          counterMinggu++; //nambah minggu
          backing++;
          main();
        }
        else{
        backing++;
        main();
        }
      }
      else{
        errorHandling();
      }
      break;
    }

    case 3:{ //ini print2 doang, printannya ntar ganti
      loading();
      printf("Selamat datang di program ESCourt (e-Sallary Checker by ourt)\n");
      printf("Program ini merupakan program perekam dan pengolah banyak jam kerja pegawai\n");
      printf("Pegawai diwajibkan untuk bekerja minimal sebanyak 40 jam setiap minggu\n");
      printf("Dengan ketentuan : \n");
      printf("- Bebas memilih hari asal akumulasi jam kerja tiap minggu tetap 40 jam\n");
      printf("- Besar nominal gaji sebesar Rp. 25.000,00/jam\n");
      printf("- Gaji diberikan pada akhir bulan, jika ada suatu minggu yang tidak terpenuhi kuotanya,\n");
      printf("- total gaji akan dikurangi sebesar 25(x)% \n  dengan (x) banyak minggu yang tidak terpenuhi dan gaji pada minggu itu tidak akan dihitung\n");
      printf("- Pegawai diharapkan dapat menginput data sesuai dengan data real time\n");
      printf("\nSekian bantuan dari program ini, pilih [1] untuk untuk ke menu awal : ");
      scanf("%d", &input);
      if(input==1){
        main();
        backing++;
      }
      else{
        errorHandling();
      }
      break;
    }

    case 4:{ //keluar di tengah2
      loading();
      printf("Selamat beristirahat! Jangan lupa untuk memenuhi jam kerja agar gaji tidak dipotong:)");
      return 0;
      break;
    }
    default : {
      errorHandling();
    }
  }
}

//--------------------------------modular--------------------------------------------------

void loading(){
  int i;
  fflush(stdin);
  system("cls");
  printf("Loading");

  for (i=1;i<=5;i++){
    printf(".");
    Sleep(50);
  }

  system("cls");
}

void menu(){
  if(counterHari>=29){//klo udh hari 29, bakal masuk menu yg lain trus print slip gaji deh
    printf("Anda telah melalui bulan kerja pada minggu ini,\nsilahkan cetak slip gaji untuk dilaporkan dan untuk bukti pengambilan gaji\n");
    system("pause");
    slipgaji();
  }
  else{
  printf("[1] Masukan banyak jam kerja (hari ini)\n[2] Lihat total jam kerja\n[3] Bantuan\n[4] Keluar\n\n[0]Lanjut ke hari besok\n");
  printf("\n\nHari ke-%d\nMinggu ke-%d\n\n", counterHari, counterMinggu);
  }
}

int timeCheck(){//pokoknya ini yg buat ngolah selisih waktu masuk sama keluar
  int a,b,x,y,jam,menit;
  printf("Apakah anda ingin memasukan jam kerja?\nPilih [1] untuk memasukan jam kerja atau pilih [2] kembali ke menu utama\n");
  scanf("%d", &input);

  if(input==1){
    loading();
    printf("Masukan jam masuk : \n");
    scanf("%d.%d",&a,&b);
    printf("Masukan jam keluar : \n");
    scanf("%d.%d",&x,&y);

    if(a>23 || x>23 || a<0 || x<0){
      printf("\nWarning!!!\nInput tidak relevan, masukan jam yang bukan angka negatif dan tidak lebih besar dari 23");
      Sleep(2000);
      loading();
      timeCheck();
    }

    else if(b>59 || y>59 || b<0 || y<0){
      printf("\nWarning!!!\nInput tidak relevan, masukan menit yang bukan angka negatif dan tidak lebih dari 59");
      Sleep(2000);
      loading();
      timeCheck();
    }

    else if(a>x){
      errorHandling();
    }

    else{
      if(y<b){
        y+=60;
        x-=1;
      }
      jam=x-a;
      menit=y-b;
      sum=60*jam+menit;

      if(counterHari<=7){ //4 tipikal kebawah ini buat nyimpen ke array
        minggu1[counterHari]=sum;
      }

      else if(counterHari>7 && counterHari<=14){
        minggu2[counterHari-7]=sum;
      }

      else if(counterHari>14 && counterHari<=21){
        minggu3[counterHari-14]=sum;
      }

      else{
        minggu4[counterHari-21]=sum;
      }

      printf("----------------------------------------------------");
      printf("\nBanyak anda bekerja hari ini sebesar %d jam %d menit\n", jam,menit);
    }
  }

  else if(input==2){
    main();
  }

  else{
    errorHandling();
  }
}

int errorHandling(){ //modular errorHandling
  printf("\nWarning!!!\nInput tidak relevan");
  Sleep(2000);
  main();
  backing++;
}

int sumChecker(){ //manggil data yang udh disimpen di array tadi (data jam hari itu sama minggu itu)

  if(counterHari<=7){
    sum=minggu1[counterHari];
    for(i=1;i<=7;i++){
      saver+=minggu1[i];
    }
  }

  else if(counterHari>7 && counterHari<=14){
    sum=minggu2[counterHari-7];
    for(i=1;i<=7;i++){
      saver+=minggu2[i];
    }
  }

  else if(counterHari>14 && counterHari<=21){
    sum=minggu3[counterHari-14];
    for(i=1;i<=7;i++){
      saver+=minggu3[i];
    }
  }

  else{
    sum=minggu4[counterHari-21];
    for(i=1;i<=7;i++){
      saver+=minggu4[i];
    }
  }
}

int sumAkhir(){ //ini klo buat akhir2 masuk slip gaji, semua jam tiap minggu dijumlahin
	int saver1=0, saver2=0, saver3=0, saver4=0;
	for(i=1;i<=7;i++){
		saver1+=minggu1[i];
		saver2+=minggu2[i];
		saver3+=minggu3[i];
		saver4+=minggu4[i];
	}
  if(saver1<2400){//klo ga diatas 40jam = denda boi
    denda++;
  }
  if(saver2<2400){
    denda++;
  }
  if(saver3<2400){
    denda++;
  }
  if(saver4<2400){
    denda++;
  }
}

int saverChecker(int a, int b){ //ngecek trus ngeprint klo minggu itu tuh terpenuhi atau kagak
  printf("Kuota minggu-%d : ", b);
  if(a>=2400){
    printf("Terpenuhi (%d jam %d menit)\n", a/60, a%60);
  }
  else{
    printf("Tidak terpenuhi (%d jam %d menit)\n", a/60, a%60);
  }
}

int slipgaji(){ //ini print slip gaji
  sumAkhir();
  FILE *cetak;
  cetak=fopen("slip gaji.txt", "w");
    fprintf(cetak, "NAMA : %s \nNomor Induk Pegawai : %d\n\n", name[k], pass[k]);
    fprintf(cetak,"   Minggu 1        Minggu 2      Minggu 3       Minggu 4\n");
	for(i=1;i<=7;i++){ //looping print jam kerja tiap semua harinya
    fprintf(cetak, "   Hari ke-%d      Hari ke-%d     Hari ke-%d     Hari ke-%d\n", i,i+7,i+14,i+21);
    fprintf(cetak, " %d jam %d menit  %d jam %d menit  %d jam %d menit  %d jam %d menit\n", minggu1[i]/60, minggu1[i]%60, minggu2[i]/60, minggu2[i]%60, minggu3[i]/60, minggu3[i]%60, minggu4[i]/60, minggu4[i]%60);
    fprintf(cetak, "----------------------------------------------------------------------\n");
  }
  fprintf(cetak,"\nTotal Minggu 1 : %d jam %d menit", saver1/60, saver1%60);
  fprintf(cetak,"\nTotal Minggu 2 : %d jam %d menit", saver2/60, saver2%60);
  fprintf(cetak,"\nTotal Minggu 3 : %d jam %d menit", saver3/60, saver3%60);
  fprintf(cetak,"\nTotal Minggu 4 : %d jam %d menit", saver4/60, saver4%60);
  fprintf(cetak,"\n--------------------------------- +\n");
  fprintf(cetak, "Total = %d jam %d menit\n\n", (saver1+saver2+saver3+saver4)/60, (saver1+saver2+saver3+saver4)%60);
  int totalJam=((saver1+saver2+saver3+saver4)/60)*45000;
  float totalMenit=((saver1+saver2+saver3+saver4)%60)*45000/60;
  float totalGaji=totalJam+totalMenit;
  fprintf(cetak,"Gaji(jam) = %d x Rp 45000 = Rp. %d\n", (saver1+saver2+saver3+saver4)/60, totalJam);
  fprintf(cetak,"Gaji(menit) = %d/60 x Rp. 45000 = Rp. %.2f\n", (saver1+saver2+saver3+saver4)%60, totalMenit);
  fprintf(cetak,"Denda = %d x Rp. 500000 = %d\n", denda, denda*500000);
  fprintf(cetak,"Gaji Bersih = Rp. %d + Rp. %.2f = Rp. %.2f \n", totalJam, totalMenit, totalGaji);
  fprintf(cetak,"\nGAJI AKHIR = Rp. %.2f - Rp. %d = Rp. %.2f", totalGaji,denda*500000, totalGaji-(denda*500000));
  fclose(cetak);
  exit(0);
}
