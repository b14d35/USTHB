import { Component, OnInit } from '@angular/core';
import { Service } from 'src/app/model/service.model';
import { Hebergement } from 'src/app/model/hebergement.model';
import { Suite } from 'src/app/model/suite.model';
import { Chambre } from 'src/app/model/chambre.model';
import { Client } from 'src/app/model/client.model';
import { Sejour } from 'src/app/model/sejour.model';
import { Piscine } from 'src/app/model/piscine.model';
import { Thalasso } from 'src/app/model/thalasso.model';
import { Garderie } from 'src/app/model/garderie.model';
import { ServiceReserve } from 'src/app/model/serviceReserve.model';

@Component({
  selector: 'app-exercice2',
  templateUrl: './exercice2.component.html',
  styleUrls: ['./exercice2.component.scss']
})
export class Exercice2Component implements OnInit {
  x = Date.now();
  // Infos De l'hotel
  servicesHotel: Service[];
  hebergementsHotel: Hebergement[];
  // Le client
  client: Client;
  // L'etape 1.Infos 2.Hebergement 3.Service
  etape = 1;
  // Infos clients temps
  nomCLient = '';
  prenomClient = '';
  sexeClient = 'Homme';
  situationCLient = 'Celebataire';
  // Info Sejour Temporaire
  dateDebut = new Date();
  dateFin = new Date();
  choixUser: number[];
  // Services
  choixService = 0;
  nbPrs = 0;
  // Erreurs
  erreurDate:string;
  erreurReserve:string;
  erreurDate2:string;
  nomOUprenom:string;
  depassement:string;
  constructor() { }

  ngOnInit() {
    this.servicesHotel = [];
    for (let index = 0; index < 20; index++) {
      const rand = Math.random();
      if (rand > 0.66) {
        this.servicesHotel.push(new Piscine(index + 1, 9, 19));
      } else if (rand > 0.33) {
        this.servicesHotel.push(new Thalasso(index + 1, 2000));
      } else {
        this.servicesHotel.push(new Garderie(index + 1, 100, 1500));
      }
    }
    this.hebergementsHotel = [];
    for (let index = 0; index < 50; index++) {
      this.hebergementsHotel.push(
        Math.random() > 0.5 ?
          new Suite((index % 10) + 1, index + 1, 5, 1000 * (15 - (index % 10))) :
          new Chambre((index % 10) + 1, index + 1, 3, 500 * (15 - (index % 10)))
      );
    }
  }

  ajouterClient() {
    this.nomOUprenom = '';
    if (this.nomCLient !== '' && this.prenomClient !== '') {
      this.client = new Client(this.nomCLient, this.prenomClient, this.sexeClient, this.situationCLient);
      this.etape = 2;
    }else{
      this.nomOUprenom = (this.nomCLient === '')? 'Inserer le Nom': 'Inserer le Prenom';
      this.nomOUprenom += (this.prenomClient === '' && this.nomCLient === '')? ' et le Prenom': '';
    }

  }
  supprimerInfos() {
    this.nomCLient = '';
    this.prenomClient = '';
    this.sexeClient = 'Homme';
    this.situationCLient = 'Celebataire';
  }

  affecterSejour() {
    const nbj = ((new Date(this.dateFin)).getTime() - (new Date(this.dateDebut)).getTime()) / (1000 * 3600 * 24);
    const neg = ((new Date(this.dateDebut)).getTime() - (new Date()).getTime()) / (1000 * 3600 * 24);
    this.erreurDate = '';
    this.erreurDate2 = '';
    this.erreurReserve = '';
    if(this.choixUser === [] || this.choixUser === undefined){
      this.erreurReserve = 'Aucune reservation';
    }
    if(neg <= 0){
      this.erreurDate = 'La date de debut de sejour ne peut pas etre inferieure a la date d\'aujourd\'hui';
    }
    if(nbj <= 0){
      this.erreurDate2 += 'La date de fin de sejour ne peut pas etre inferieure a la date de debut de sejour';
    }
    if (this.choixUser !== [] && nbj > 0 && neg > 0) {
      let choixHeb: Hebergement[];
      choixHeb = [];
      this.choixUser.forEach(el => {
        choixHeb.push(this.hebergementsHotel[el - 1]);
      });
      this.client.affecterSejour(new Sejour(this.dateDebut, this.dateFin, choixHeb));
      this.etape = 3;
    }
  }

  ajouterService() {
    this.depassement = '';
    let ajout = this.servicesHotel[this.choixService - 1];
    if (ajout.type === 'Garderie') {
      if ((ajout as Garderie).nbMaxEnfant >= this.nbPrs) {
        this.client.addService(new ServiceReserve(ajout, this.nbPrs));
        this.nbPrs = 0;
        this.choixService = 0;
      }else{
        this.depassement = 'Vous avez depasse le nombre max d\'enfant a garder';
      }
    } else {
      this.client.addService(new ServiceReserve(ajout, this.nbPrs));
      this.nbPrs = 0;
      this.choixService = 0;
    }
  }

  viderInfosSejour() {
    this.choixUser = [];
    this.dateDebut = null;
    this.dateFin = null;
  }
}
