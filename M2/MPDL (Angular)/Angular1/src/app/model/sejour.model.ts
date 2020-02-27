import { Hebergement } from './hebergement.model';

export class Sejour {
  private $dateDebut: Date;
  private $dateFin: Date;
  private $hebergements: Hebergement[];

  constructor(dd: Date, df: Date, hebergements: Hebergement[]) {
    this.$dateDebut = dd;
    this.$dateFin = df;
    this.$hebergements = hebergements;
  }

  public get hebergements(): Hebergement[] {
    return this.$hebergements;
  }

  public get dateD(): Date {
    return this.$dateDebut;
  }

  public get dateF(): Date {
    return this.$dateFin;
  }

  public nbJours(): number {
    return ((new Date(this.$dateFin)).getTime() - (new Date(this.$dateDebut)).getTime()) / (1000 * 3600 * 24);
  }

  public calculerPrix(): number {
    return this.$hebergements.map(x => x.prix * this.nbJours()).reduce((somme, valC) => somme + valC);
  }

}
