void Smooth(TGraph * g, int N = 6, int flag = 0, TString signal = "T2tt") {
  TGraph * old = (TGraph*) g->Clone();
  //int N = (n%2==0?n+1:n);
  if (N > 2 * g->GetN())
    N = 2 * g->GetN() - 1;
  
  double gauss[N];
  double sigma = (double) N / 4.;
  double sum = 0;
  double lim = (double) N / 2.;
  TF1 *fb = new TF1("fb", "gaus(0)", -lim, lim);
  fb->SetParameter(0, 1. / (sqrt(2 * 3.1415) * sigma));
  fb->SetParameter(1, 0);
  fb->SetParameter(2, sigma);
  for (int i = 0; i < N; ++i) {
    gauss[i] = fb->Integral(-lim + i, -lim + i + 1);
    sum += gauss[i];
  }
  for (int i = 0; i < N; ++i)
    gauss[i] /= sum;

  double xi, yi, xf, yf;
  for (int i = 0; i < g->GetN(); ++i) {
    double avy = 0., avx = 0., x, x0, y, y0;
    int points = 0;
    for (int j = i - N / 2; j <= i + N / 2; ++j) {
      if (j < 0) {
        old->GetPoint(0, x, y);
        xi = x;
        yi = y;
      }		
      else if (j >= g->GetN()) {
        old->GetPoint(old->GetN() - 1, x, y);
        xf = x;
        yf = y;
      }	
      else 
        old->GetPoint(j, x, y);

      avy += y * gauss[points];
      avx += x * gauss[points];
      
      if (i == j) {
        x0 = x;
        y0 = y;
      }	
      ++points;
    }
    //if(i - N / 2 < 0 || i + N / 2 >= g->GetN() || i < 5*N || i > g->GetN() - 5*N){
    //  cout << "i: " << i << endl;
    //  cout << "xi/yi = " << xi << "/" << yi << endl;
    //  cout << "xf/yf = " << xf << "/" << yf << endl;
    //  cout << "x/y = " << x0 << "/" << y0 << endl;
    //  cout << "avx/y = " << avx << "/" << y0 << endl;
    //}

    // KenH check outcome of smoothing
    // printf("i,xi,yi,xf,yf: %8d, %8.2f %8.2f, %8.2f %8.2f, %8.2f %8.2f, %8.2f %8.2f\n",i,xi,yi,xf,yf,avx,avy,x0,y0);

    if      ((flag==1 && i - N / 2 < 0 ) || (flag==2 && i + N / 2 >= g->GetN()))
      g->SetPoint(i, x0, avy);
    else if ((flag==1 && i + N / 2 >= g->GetN()) || (flag==2 && i - N / 2 < 0 ))
      g->SetPoint(i, avx, y0);
    else if ((signal.Contains("T2fbd") || signal.Contains("T2bWC")) && (y0 <= 5 || y0 >= 80))
      g->SetPoint(i, x0, y0);
    else if (signal.Contains("T2cc") && (y0 <= 10 || y0 >= 80))
      g->SetPoint(i, x0, y0);
    else if ((signal.Contains("T2tb") || signal.Contains("T2bW") )  && y0 <= 10)
      g->SetPoint(i, x0, y0);
    else if ((flag==3 && (xf != xi && yf != yi) && i + N / 2 >= g->GetN()) || (flag==2 && i - N / 2 < 0 ))
      g->SetPoint(i, avx, y0);
    //KenH starts
    else if ((signal.Contains("TChiWW") || signal.Contains("TChiWH"))  && y0 <= 10)
      g->SetPoint(i, avx, y0);
    else if (signal.Contains("TChiWZ") && (i==0 || i==g->GetN()-1))
      g->SetPoint(i, avx, y0);
    //KenH ends
    else
      g->SetPoint(i, avx, avy);
  }
  delete old;
}
