/*************************************************
 * chemnetworks.h                                *
 *                                               *
 * Author: Abdullah Ozkanlar                     *
 *         abdullah.ozkanlar@wsu.edu             *
 *                                               *
 * A. Clark Research Lab, Chemistry Department   *
 * Washington State University, Pullman/WA 99164 *
 *************************************************/

#ifndef CHEMNETWORKS_ORIG_H
#define CHEMNETWORKS_ORIG_H

#include <stdio.h>

#include "chemnetworks.h"

#define FLN 256

namespace CN_NS {
  
  class ChemNetworkOrig : public ChemNetwork {
  public : 
    ChemNetworkOrig();
    ~ChemNetworkOrig() {};
    
    void input_read(int, char * []);
    void input_process(int, char * []);

  private : 

    /* string manipulation */
    
    int findf(FILE *fd, int n, ...);
    
    /* graph types */
    
    // here I changed the graph functions, consider an upper boundary and a lower boundary
    
    void graph_ss(double *atmS1, int nd1, int nsolvent1, int nAtomS1, int s1s1hbdn, int *s1a, int *s1b, double *s1as1bBDmin, double *s1as1bBDmax,
		  int s1s1hban, int *s1s1v1, int *s1s1v2, int *s1s1v3, int *s1s1v4, int *s1s1v5, double *s1s1v6, double *s1s1v7,
		  int pbc, double xside, double yside, double zside, FILE *outputfGraphS1S1, FILE *outputfGeodS1S1);
    
    void graph_sAsB(double *atmS1, double *atmS2, int nd1, int nd2, int nsolvent1, int nsolvent2, int nAtomS1, int nAtomS2,
		    int s1s2hbdn, int *s12a, int *s12b, double *s12as12bBDmin, double *s12as12bBDmax, 
		    int s1s2hban, int *s1s2v1, int *s1s2v2, int *s1s2v3, int *s1s2v4, int *s1s2v5, double *s1s2v6, double *s1s2v7,
		    int pbc, double xside, double yside, double zside, FILE *outputfGraphS1S2, FILE *outputfGeodS1S2);
    
    void graph_st(double *atmS1, double *atmT1, int nd1, int nd2, int nsolvent1, int nsolute1, int nAtomS1, int nAtomT1, int s1t1cutoffnum, int *s1t1a, int *s1t1b,
		  double *s1t1cutoffmin, double *s1t1cutoffmax, int pbc, double xside, double yside, double zside, FILE *outputfGraphS1T1, FILE *outputfGeodS1T1);
    
    void search_pbc_gss(int boxid, double *atmS1, double *atmS1x, int nd1, int nsolvent1, int nAtomS1, int s1s1hbdn, int *s1a, int *s1b, double *s1as1bBDmin, double *s1as1bBDmax, int s1s1hban,
			int *s1s1v1, int *s1s1v2, int *s1s1v3, int *s1s1v4, int *s1s1v5, double *s1s1v6, double *s1s1v7, FILE *outputfGraphS1S1, FILE *outputfGeodS1S1);
    
    void search_pbc_gsAsB(int boxid, double *atmS1, double *atmS2x, int nd1, int nd2, int nsolvent1, int nsolvent2, int nAtomS1, int nAtomS2, int s1s2hbdn, 
			  int *s12a, int *s12b, double *s12as12bBDmin, double *s12as12bBDmax, int s1s2hban, int *s1s2v1, int *s1s2v2, int *s1s2v3, int *s1s2v4, int *s1s2v5, double *s1s2v6, double *s1s2v7,
			  FILE *outputfGraphS1S2, FILE *outputfGeodS1S2);
    
    void search_pbc_gst(int boxid, double *atmT1, double *atmS1x, int nd1, int nd2, int nsolvent1, int nsolute1, int nAtomS1, int nAtomT1, int s1t1cutoffnum,
			int *s1t1a, int *s1t1b, double *s1t1cutoffmin, double *s1t1cutoffmax,  FILE *outputfGraphS1T1, FILE *outputfGeodS1T1);
    
    /* water dipoles */
    
    void graph_st_dip(double *atmS1, double *atmT1, int nd1, int nd2, int nsolvent1, int nsolute1, int nAtomS1, int nAtomT1, int s1t1cutoffnum, int *s1t1a, int *s1t1b,
		      double *s1t1cutoffmax, int pbc, double xside, double yside, double zside, int opos, int h1pos, int h2pos, 
		      FILE *outputfGraphS1T1, FILE *outputfGeodS1T1, FILE *outputfS1T1Dip);
    
    void search_pbc_gst_dip(int boxid, double *atmT1, double *atmS1x, int nd1, int nd2, int nsolvent1, int nsolute1, int nAtomS1, int nAtomT1, int s1t1cutoffnum, 
			    int *s1t1a, int *s1t1b, double *s1t1cutoffmax, int opos, int h1pos, int h2pos, 
			    FILE *outputfGraphS1T1, FILE *outputfGeodS1T1, FILE *outputfS1T1Dip);
    
    void graph_sAsB_dip(double *atmS1, double *atmS2, int nd1, int nd2, int nsolvent1, int nsolvent2, int nAtomS1, int nAtomS2,
			int s1s2hbdn, int *s12a, int *s12b, double *s12as12bBDmax, 
			int s1s2hban, int *s1s2v1, int *s1s2v2, int *s1s2v3, int *s1s2v4, int *s1s2v5, double *s1s2v6, 
			int pbc, double xside, double yside, double zside, int opos, int h1pos, int h2pos, int watid, int solid, 
			FILE *outputfGraphS1S2, FILE *outputfGeodS1S2, FILE *outputfS1S2Dip);
    
    void search_pbc_gsAsB_dip(int boxid, double *atmS1, double *atmS2x, int nd1, int nd2, int nsolvent1, int nsolvent2, int nAtomS1, int nAtomS2, int s1s2hbdn,
			      int *s12a, int *s12b, double *s12as12bBDmax, int s1s2hban, int *s1s2v1, int *s1s2v2, int *s1s2v3, int *s1s2v4, int *s1s2v5, double *s1s2v6,
			      int opos, int h1pos, int h2pos, int watid, int solid,
			      FILE *outputfGraphS1S2, FILE *outputfGeodS1S2, FILE *outputfS1S2Dip);
    
    double dipole_angle(double *atmT, double *atmS, int i, int j, int *stb, int *sta, int crt, int opos, int h1pos, int h2pos);
    
    /* structures */
    
    void hringsearch(double *atmS1, int nd1, int opos, int nsolvent1, int nAtomS1, int s1s1hbdn, int *s1a, int *s1b, double *s1as1bBDmax, 
		     int s1s1hban, int *s1s1v1, int *s1s1v2, int *s1s1v3, int *s1s1v4, int *s1s1v5, double *s1s1v6, int hiso,
		     FILE *outputfHRing, char *foutputHRingIso);
    
    void hbooksearch(double *atmS1, int nd1, int opos, int nsolvent1, int nAtomS1, int s1s1hbdn, int *s1a, int *s1b, double *s1as1bBDmax,
		     int s1s1hban, int *s1s1v1, int *s1s1v2, int *s1s1v3, int *s1s1v4, int *s1s1v5, double *s1s1v6, int hiso,
		     FILE *outputfHBook, char *foutputHBookIso);
    
    void hprismsearch(double *atmS1, int nd1, int opos, int nsolvent1, int nAtomS1, int s1s1hbdn, int *s1a, int *s1b, double *s1as1bBDmax, 
		      int s1s1hban, int *s1s1v1, int *s1s1v2, int *s1s1v3, int *s1s1v4, int *s1s1v5, double *s1s1v6, int hiso,
		      FILE *outputfHPrism, char *foutputHPrismIso);
    
    void hcagesearch(double *atmS1, int nd1, int opos, int nsolvent1, int nAtomS1, int s1s1hbdn, int *s1a, int *s1b, double *s1as1bBDmax, 
		     int s1s1hban, int *s1s1v1, int *s1s1v2, int *s1s1v3, int *s1s1v4, int *s1s1v5, double *s1s1v6, int hiso,
		     FILE *outputfHCage, char *foutputHCageIso);
    
    void hbagsearch(double *atmS1, int nd1, int opos, int nsolvent1, int nAtomS1, int s1s1hbdn, int *s1a, int *s1b, double *s1as1bBDmax, 
		    int s1s1hban, int *s1s1v1, int *s1s1v2, int *s1s1v3, int *s1s1v4, int *s1s1v5, double *s1s1v6, int hiso,
		    FILE *outputfHBag, char *foutputHBagIso);
    
    void hboatsearch(double *atmS1, int nd1, int opos, int nsolvent1, int nAtomS1, int s1s1hbdn, int *s1a, int *s1b, double *s1as1bBDmax, 
		     int s1s1hban, int *s1s1v1, int *s1s1v2, int *s1s1v3, int *s1s1v4, int *s1s1v5, double *s1s1v6, int hiso,
		     FILE *outputfHBoat, char *foutputHBoatIso);
    
    void hchairsearch(double *atmS1, int nd1, int opos, int nsolvent1, int nAtomS1, int s1s1hbdn, int *s1a, int *s1b, double *s1as1bBDmax, 
		      int s1s1hban, int *s1s1v1, int *s1s1v2, int *s1s1v3, int *s1s1v4, int *s1s1v5, double *s1s1v6, int hiso,
		      FILE *outputfHChair, char *foutputHChairIso);
    
    void hprismbooksearch(double *atmS1, int nd1, int opos, int nsolvent1, int nAtomS1, int s1s1hbdn, int *s1a, int *s1b, double *s1as1bBDmax, 
			  int s1s1hban, int *s1s1v1, int *s1s1v2, int *s1s1v3, int *s1s1v4, int *s1s1v5, double *s1s1v6, int hiso,
			  FILE *outputfHPrismBook, char *foutputHPrismBookIso);
    
    int check_isolated_hexamer(double *atmS, int nAtomS, int s1s1hbdn, int *s1a, int *s1b, double *s1as1bBDmax, int s1s1hban,
			       int *s1s1v1, int *s1s1v2, int *s1s1v3, int *s1s1v4, int *s1s1v5, double *s1s1v6,
			       int atma, int atmb, int atmc, int atmd, int atme, int atmf);
    
    void hpentamersearch(double *atmS1, int nd1, int opos, int nsolvent1, int nAtomS1, int s1s1hbdn, int *s1a, int *s1b, double *s1as1bBDmax, 
			 int s1s1hban, int *s1s1v1, int *s1s1v2, int *s1s1v3, int *s1s1v4, int *s1s1v5, double *s1s1v6, int hiso,
			 FILE *outputfPentamer, char *foutputPentamerIso);
    
    int check_isolated_pentamer(double *atmS, int nAtomS, int s1s1hbdn, int *s1a, int *s1b, double *s1as1bBDmax, int s1s1hban, 
				int *s1s1v1, int *s1s1v2, int *s1s1v3, int *s1s1v4, int *s1s1v5, double *s1s1v6, 
				int atma, int atmb, int atmc, int atmd, int atme);
    
    void htetramersearch(double *atmS1, int nd1, int opos, int nsolvent1, int nAtomS1, int s1s1hbdn, int *s1a, int *s1b, double *s1as1bBDmax, 
			 int s1s1hban, int *s1s1v1, int *s1s1v2, int *s1s1v3, int *s1s1v4, int *s1s1v5, double *s1s1v6, int hiso,
			 FILE *outputfTetramer, char *foutputTetramerIso);
    
    int check_isolated_tetramer(double *atmS, int nAtomS, int s1s1hbdn, int *s1a, int *s1b, double *s1as1bBDmax, int s1s1hban, 
				int *s1s1v1, int *s1s1v2, int *s1s1v3, int *s1s1v4, int *s1s1v5, double *s1s1v6, 
				int atma, int atmb, int atmc, int atmd);
    
    void htrimersearch(double *atmS1, int nd1, int opos, int nsolvent1, int nAtomS1, int s1s1hbdn, int *s1a, int *s1b, double *s1as1bBDmax, 
		       int s1s1hban, int *s1s1v1, int *s1s1v2, int *s1s1v3, int *s1s1v4, int *s1s1v5, double *s1s1v6, int hiso,
		       FILE *outputfTrimer, char *foutputTrimerIso);
    
    int check_isolated_trimer(double *atmS, int nAtomS, int s1s1hbdn, int *s1a, int *s1b, double *s1as1bBDmax, int s1s1hban, 
			      int *s1s1v1, int *s1s1v2, int *s1s1v3, int *s1s1v4, int *s1s1v5, double *s1s1v6, 
			      int atma, int atmb, int atmc);
    
    int prismbook_check(double *atmSX, int ndX, int opos, int sXsXhbdn, int *sXa, int *sXb, double *sXasXbBDmax, 
			int sXsXhban, int *sXsXv1, int *sXsXv2, int *sXsXv3, int *sXsXv4, int *sXsXv5, double *sXsXv6,
			int atmaX, int atmbX, int atmcX, int atmdX, int atmeX, int atmfX);
    
    int ring_check(double *atmSX, int ndX, int opos, int sXsXhbdn, int *sXa, int *sXb, double *sXasXbBDmax, 
		   int sXsXhban, int *sXsXv1, int *sXsXv2, int *sXsXv3, int *sXsXv4, int *sXsXv5, double *sXsXv6,
		   int atmaX, int atmbX, int atmcX, int atmdX, int atmeX, int atmfX);
    
    /* distance */
    
    double distance(double *atmS, int i, int j,int *sa, int *sb, int crt);
    
    double distanceMix(double *atmS1, double *atmS2, int i, int j,int *sa, int *sb, int crt);
    
    double distanceOxOy(double *atmS, int i, int j, int opos);
    
    /* angle */
    
    double angle(double dist, double dist2, double hyptns);
    
    /* dihedral */
    
    double dihedral(double *atmS, int atm1, int atm2, int atm3, int atm4, int opos);
    
    double dihedral2(double *atmS, int atm1, int atm2, int atm3, int atm4, int opos);
    
    /* permutations */
    
    int perm6(int v6[], int n, int i, int v2[], int *e);
    
    void swap6(int v6[], int i, int j);
    
    int perm5(int v5[], int n, int i, int v2[], int *e);
    
    void swap5(int v5[], int i, int j);
    
    int perm4(int v4[], int n, int i, int v2[], int *e);
    
    void swap4(int v4[], int i, int j);
    
    int perm3(int v3[], int n, int i, int v2[], int *e);
    
    void swap3(int v3[], int i, int j);
    
    
    // geodesics
    
    void geodesics_ss(int nsolvent, int nAtomS, int EucDistS, int EucRefS, double xside, double yside, double zside, char *foutputGeodSS, char *finput);
    
    void geodesics_sAsB(int nsolventA, int nAtomSA, int nsolventB, int nAtomSB, int EucDistSASB, int EucRefSASBsa, int EucRefSASBsb, double xside, double yside, double zside, 
			char *foutputGeodSASB, char *finputA, char *finputB);
    
    void geodesics_sAsBsC(int nsolventA, int nAtomSA, int nsolventB, int nAtomSB, int nsolventC, int nAtomSC, int EucDistSASBSC, int EucRefSASBSCsa, int EucRefSASBSCsb, int EucRefSASBSCsc, 
			  double xside, double yside, double zside, char *foutputGeodSASBSC, char *finputA, char *finputB, char *finputC);
    
    void GetPath(int i, int j, int **next, int **gdmatrix, FILE *fout);
    
    struct edge{
      int nodea;
      int nodeb;
      int change[3];
    };
    
    int FindChange(int startnode, int endnode, struct edge* edgelist, int numedgelist);
    
    // polyhedra
    
    void polyhedra_st(double *atmS1, double *atmT1, int nd1, int nd2, int nsolvent1, int nsolute1, int nAtomS1, int s1t1cutoffnum, int *s1t1a, int *s1t1b, double *s1t1cutoff, int pbc, double xside, double yside, double zside, FILE *outputPolys, int maxshellsize, double**edgebds, int whichatmT1, int whichatmdexT1);
    
    void shellist_and_distmtx(int *shellist, double **shelldistmtx, double *atmS1, double *atmT1, int nd1, int nd2, int nsolvent1, int nsolute1, int nAtomS1, int s1t1cutoffnum, int *s1t1a, int *s1t1b, double *s1t1cutoff, int pbc, double xside, double yside, double zside, int *shellsize, int maxshellsize, int whichatmT1, int whichatmdexT1);
    
    void search_pbc_solute(int *shellist_indx, int *shellist, double *atmT1, double *atmS1box, int nd1, int nd2, int nsolvent1, int nsolute1, int nAtomS1, int s1t1cutoffnum, int *s1t1a, int *s1t1b, double *s1t1cutoff, int *eachnode_critatm, int whichatmT1, int whichatmdexT1);
    
    double solvent_dist(double *atmS1, double *atmS1x, double *atmS1y, double *atmS1z, double *atmS1xy, double *atmS1yz, double *atmS1zx,
			double *atmS1xminy, double *atmS1minyz, double *atmS1zminx, double *atmS1xyz, double *atmS1xyminz,
			double *atmS1minxyz, double *atmS1xminyz, double *atmS1minx, double *atmS1miny, double *atmS1minz,
			double *atmS1minxminy, double *atmS1minyminz, double *atmS1minzminx, double *atmS1minxy,
			double *atmS1yminz, double *atmS1minzx, double *atmS1minxminyminz, double *atmS1minxminyz,
			double *atmS1xminyminz, double *atmS1minxyminz, int shellsize, int *shellist, int pbc, int solvent_node_a, int solvent_node_b, int *crit_atom_holder_a, int *crit_atom_holder_b);
    
    double *pagerank(int ** adjM, int nodes, double damp, double tolerance);
    
    void basearray(int n, int length, int *narray, int base);
    
    typedef struct poly
    {
      char *name;
      int *edgelist;
      int **adjmat;
      int nvtx; //number of vertices
      int nedge; //number of edges
      double *prvect; //vector of pageranks
      double char_pr; //characteristic pagerank
    } poly;
    
    void makeallpolys(poly **polylist);
    
    poly *poly_create(char *name, int *edgelist, int nvtx, int nedge);
    
    int polymatch(poly **polylist, int **adjacency_matrix, double **shelldistmtx, int **temp_adjm, int shellsize, int numofpolies, double damp, double tolerance, int **possible_edgelist, int poss_edge_num);
    
    void poly_destroy(poly *polyhedron);
    
    void pdfshell(double **shellist_and_distmtx, int shellsize, FILE *outputshellpdf);
    
    void varyShellFunction(double varyMin, double varyMax, int varyBreaks, int maxshellsize, FILE *outvariedShellDists, double *atmS1, double *atmT1, int node1Start, int node2Start, int nsolvent1, int nsolute1, int nAtomS1, int *s1t1a, int *s1t1b, double *s1t1cutoff, int pbc, double xside, double yside, double zside, int whichatmT1, int whichatmdexT1, int s1t1cutoffnum);
    
    int *findunique(int *list, int numinlist, int *numunique);


//     FILE *outputf;         /* Log file*/
       FILE *fd;              /* file pointer */
       FILE *fsolvent1;
       FILE *fsolvent2;
       FILE *fsolvent3;
       FILE *fsolute1;
       FILE *fsolute2;

       FILE *outputfGraphS1S1;
       FILE *outputfGeodS1S1;
       FILE *outputfGraphS2S2;
       FILE *outputfGeodS2S2;
       FILE *outputfGraphS3S3;
       FILE *outputfGeodS3S3;
       FILE *outputfGraphS1S2;
       FILE *outputfGeodS1S2;
       FILE *outputfGraphS1S3;
       FILE *outputfGeodS1S3;
       FILE *outputfGraphS2S3;
       FILE *outputfGeodS2S3;
       FILE *outputfGraphS1T1;
       FILE *outputfGeodS1T1;
       FILE *outputfGraphS1T2;
       FILE *outputfGeodS1T2;
       FILE *outputfGraphS2T1;
       FILE *outputfGeodS2T1;
       FILE *outputfGraphS2T2;
       FILE *outputfGeodS2T2;
       FILE *outputfGraphS3T1;
       FILE *outputfGeodS3T1;
       FILE *outputfGraphS3T2;
       FILE *outputfGeodS3T2;
       FILE *outputfGraphS1S2S3;
       FILE *outputfGeodS1S2S3;
       FILE *outputfNumnodesS1S1;
       FILE *outputfNumnodesS2S2;
       FILE *outputfNumnodesS3S3;
       FILE *outputfNumnodesS1S2;
       FILE *outputfNumnodesS1S3;
       FILE *outputfNumnodesS2S3;
       FILE *outputfNumnodesS1T1;
       FILE *outputfNumnodesS1T2;
       FILE *outputfNumnodesS2T1;
       FILE *outputfNumnodesS2T2;
       FILE *outputfNumnodesS3T1;
       FILE *outputfNumnodesS3T2;
       FILE *outputfNumnodesS1S2S3;
       FILE *outputfS1T1Dip;
       FILE *outputfS1T2Dip;
       FILE *outputfS2T1Dip;
       FILE *outputfS2T2Dip;
       FILE *outputfS3T1Dip;
       FILE *outputfS3T2Dip;
       FILE *outputfS1S2Dip;
       FILE *outputfS1S3Dip;
       FILE *outputfS2S3Dip;

       FILE *outputfHRing;
       FILE *outputfHBook;
       FILE *outputfHPrism;
       FILE *outputfHCage;
       FILE *outputfHBag;
       FILE *outputfHBoat;
       FILE *outputfHChair;
       FILE *outputfHPrismBook;
       FILE *outputfPentamer;
       FILE *outputfTetramer;
       FILE *outputfTrimer;
    
       FILE *outputPolys;
    FILE *outputPdfShell;
  //  FILE *outvariedShellDists;

       char line[FLN];

       char finput[FLN];      /* intput file name */
       char foutput[FLN];
       char foutputGraphS1S1[FLN];
       char foutputGeodS1S1[FLN];
       char foutputGraphS2S2[FLN];
       char foutputGeodS2S2[FLN];
       char foutputGraphS3S3[FLN];
       char foutputGeodS3S3[FLN];
       char foutputGraphS1S2[FLN];
       char foutputGeodS1S2[FLN];
       char foutputGraphS1S3[FLN];
       char foutputGeodS1S3[FLN];
       char foutputGraphS2S3[FLN];
       char foutputGeodS2S3[FLN];
       char foutputGraphS1T1[FLN];
       char foutputGeodS1T1[FLN];
       char foutputGraphS1T2[FLN];
       char foutputGeodS1T2[FLN];
       char foutputGraphS2T1[FLN];
       char foutputGeodS2T1[FLN];
       char foutputGraphS2T2[FLN];
       char foutputGeodS2T2[FLN];
       char foutputGraphS3T1[FLN];
       char foutputGeodS3T1[FLN];
       char foutputGraphS3T2[FLN];
       char foutputGeodS3T2[FLN];
       char foutputGraphS1S2S3[FLN];
       char foutputGeodS1S2S3[FLN];
       char foutputNumnodesS1S1[FLN];
       char foutputNumnodesS2S2[FLN];
       char foutputNumnodesS3S3[FLN];
       char foutputNumnodesS1S2[FLN];
       char foutputNumnodesS1S3[FLN];
       char foutputNumnodesS2S3[FLN];
       char foutputNumnodesS1T1[FLN];
       char foutputNumnodesS1T2[FLN];
       char foutputNumnodesS2T1[FLN];
       char foutputNumnodesS2T2[FLN];
       char foutputNumnodesS3T1[FLN];
       char foutputNumnodesS3T2[FLN];
       char foutputNumnodesS1S2S3[FLN];
       char foutputS1T1Dip[FLN];
       char foutputS1T2Dip[FLN];
       char foutputS2T1Dip[FLN];
       char foutputS2T2Dip[FLN];
       char foutputS3T1Dip[FLN];
       char foutputS3T2Dip[FLN];
       char foutputS1S2Dip[FLN];
       char foutputS1S3Dip[FLN];
       char foutputS2S3Dip[FLN];
       char finput2[FLN];
       char finput3[FLN];

       char foutputHRing[FLN];
       char foutputHRingIso[FLN];
       char foutputHBook[FLN];
       char foutputHBookIso[FLN];
       char foutputHPrism[FLN];
       char foutputHPrismIso[FLN];
       char foutputHCage[FLN];
       char foutputHCageIso[FLN];
       char foutputHBag[FLN];
       char foutputHBagIso[FLN];
       char foutputHBoat[FLN];
       char foutputHBoatIso[FLN];
       char foutputHChair[FLN];
       char foutputHChairIso[FLN];
       char foutputHPrismBook[FLN];
       char foutputHPrismBookIso[FLN];
       char foutputPentamer[FLN];
       char foutputPentamerIso[FLN];
       char foutputTetramer[FLN];
       char foutputTetramerIso[FLN];
       char foutputTrimer[FLN];
       char foutputTrimerIso[FLN];
       char foutputPolys[FLN];
        char foutputPdfShell[FLN];
    //char foutputVShellDists[FLN];


//     time_t now;

       int i, j, nsolventtype, nsolutetype, node1Start, node2Start, pbc;
       int nsolvent1, nsolvent2, nsolvent3, nsolute1, nsolute2, ntest;
       int gs1s1, gs2s2, gs3s3, gs1s2, gs1s3, gs2s3;
       int gs1t1, gs1t2, gs2t1, gs2t2, gs3t1, gs3t2, gs1s2s3;
       int s1s1hbdn, s1s1hban, s2s2hbdn, s2s2hban, s3s3hbdn, s3s3hban;
       int s1s2hbdn, s1s2hban, s1s3hbdn, s1s3hban, s2s3hbdn, s2s3hban;
       char **slvntatm1, **slvntatm2, **slvntatm3, **sltatm1, **sltatm2, **slvntatmtest;
       int slvntatmnum1[50], slvntatmnum2[50], slvntatmnum3[50], sltatmnum1[50], sltatmnum2[50];
       int s1a[50], s1b[50], s2a[50], s2b[50], s3a[50], s3b[50], s12a[50], s12b[50], s13a[50], s13b[50], s23a[50], s23b[50];
       int s1s1v1[50], s1s1v2[50], s1s1v3[50], s1s1v4[50], s1s1v5[50];
       int s2s2v1[50], s2s2v2[50], s2s2v3[50], s2s2v4[50], s2s2v5[50];
       int s3s3v1[50], s3s3v2[50], s3s3v3[50], s3s3v4[50], s3s3v5[50];
       int s1s2v1[50], s1s2v2[50], s1s2v3[50], s1s2v4[50], s1s2v5[50];
       int s1s3v1[50], s1s3v2[50], s1s3v3[50], s1s3v4[50], s1s3v5[50];
       int s2s3v1[50], s2s3v2[50], s2s3v3[50], s2s3v4[50], s2s3v5[50];
//       double s1s1v6[50], s2s2v6[50], s3s3v6[50], s1s2v6[50], s1s3v6[50], s2s3v6[50];    // 2015.12.14 , I want to have both lower boundary and upper boundary for HB angle, Tiecheng
       double s1s1v6[50], s1s1v7[50], s2s2v6[50], s2s2v7[50], s3s3v6[50], s3s3v7[50], s1s2v6[50], s1s2v7[50], s1s3v6[50], s1s3v7[50], s2s3v6[50], s2s3v7[50];

//       double s1as1bBD[50], s2as2bBD[50], s3as3bBD[50], s12as12bBD[50], s13as13bBD[50], s23as23bBD[50];  // 2015.12.14 , I want to have both lower boundary and upper boundary for HB distance, Tiecheng
       double s1as1bBDmin[50], s2as2bBDmin[50], s3as3bBDmin[50], s12as12bBDmin[50], s13as13bBDmin[50], s23as23bBDmin[50];
       double s1as1bBDmax[50], s2as2bBDmax[50], s3as3bBDmax[50], s12as12bBDmax[50], s13as13bBDmax[50], s23as23bBDmax[50];

       int s1t1cutoffnum, s1t2cutoffnum, s2t1cutoffnum, s2t2cutoffnum, s3t1cutoffnum, s3t2cutoffnum;
       int s1t1a[50], s1t1b[50], s1t2a[50], s1t2b[50], s2t1a[50], s2t1b[50], s2t2a[50], s2t2b[50], s3t1a[50], s3t1b[50], s3t2a[50], s3t2b[50];
//       double s1t1cutoff[50], s1t2cutoff[50], s2t1cutoff[50], s2t2cutoff[50], s3t1cutoff[50], s3t2cutoff[50];  // 2015.12.14 ,I want to have both lower boundary and upper boundary for HB distance, Tiecheng
       double s1t1cutoffmin[50], s1t2cutoffmin[50], s2t1cutoffmin[50], s2t2cutoffmin[50], s3t1cutoffmin[50], s3t2cutoffmin[50];
       double s1t1cutoffmax[50], s1t2cutoffmax[50], s2t1cutoffmax[50], s2t2cutoffmax[50], s3t1cutoffmax[50], s3t2cutoffmax[50];

       double xside, yside, zside;

       int nAtomS1, nAtomS2, nAtomS3, nAtomT1, nAtomT2;
       double *atmS1, *atmS2, *atmS3, *atmT1, *atmT2;
       char **atmTypeS1, **atmTypeS2, **atmTypeS3, **atmTypeT1, **atmTypeT2;
       int pnumnodes, ws, hring, hbook, hprism, hcage, hbag, hboat, hchair, hprismbook, hpentamer, htetramer, htrimer, hiso, opos, watid, cks;
       int scr[50];
       int gdist, gdistS1, EucDistS1, EucRefS1, gdistS2, EucDistS2, EucRefS2, gdistS3, EucDistS3, EucRefS3;
       int gdistS1S2, EucDistS1S2, EucRefS1S2s1, EucRefS1S2s2, gdistS1S3, EucDistS1S3, EucRefS1S3s1, EucRefS1S3s3, gdistS2S3, EucDistS2S3, EucRefS2S3s2, EucRefS2S3s3;
       int gdistS1S2S3, EucDistS1S2S3, EucRefS1S2S3s1, EucRefS1S2S3s2, EucRefS1S2S3s3;
       int t1watdip, t2watdip, h1pos, h2pos, trs, swatdip, solid;

    int findpolys, findpdfshell, nT1molecules; //varyshellsz
    int numunique;
    int *critlist;
    int whichatmT1, whichatmdexT1;
    int maxshellsize, shellsize, n_edg_bd; // varyBreaks;
    int *shellist, *edgbd_idx;
    double **shelldistmtx, **edgebds;
   // double varyMin, varyMax;

    
  };
}
    
#endif // CHEMNETWORKS_ORIG_H