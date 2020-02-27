import { Sejour } from './sejour.model';
import { ServiceReserve } from './serviceReserve.model';

export class Client {
  private $nom: string;
  private $prenom: string;
  private $sexe: string;
  private $etatCivil: string;
  private $services: ServiceReserve[];
  private $sejour: Sejour;

  constructor(nom: string, prenom: string, sexe: string, etatCivil: string) {
    this.$nom = nom.toUpperCase();
    this.$prenom = prenom.charAt(0).toUpperCase() + prenom.slice(1).toLowerCase();
    this.$sexe = sexe;
    this.$etatCivil = etatCivil;
    this.$services = [];
  }

  public get sejour(): Sejour {
    return this.$sejour;
  }

  public get services(): ServiceReserve[] {
    return this.$services;
  }

  public addService(x: ServiceReserve) {
    this.$services.push(x);
  }

  public affecterSejour(x: Sejour) {
    this.$sejour = x;
  }

  public prixTotalService(): number {
    return (this.$services.length !== 0) ? this.$services.map(x => x.calculerPrix()).reduce((somme, valC) => somme + valC) : 0;
  }

  public prixTotalHebergement(): number {
    return this.$sejour.calculerPrix();
  }

  public prixTotalSejour(): number {
    return this.prixTotalHebergement() + this.prixTotalService();
  }

  public getInfos(): string {
    return this.$nom + ' ' + this.$prenom;
  }
}
