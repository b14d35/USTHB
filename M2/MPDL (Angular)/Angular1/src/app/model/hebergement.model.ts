export class Hebergement {
  private $etage: number;
  private $numero: number;
  private $nbLits: number;
  private $prix: number;
  private $type: string;
  constructor(etage: number, numero: number, nbLits: number, prix: number, type: string) {
    this.$etage = etage;
    this.$numero = numero;
    this.$nbLits = nbLits;
    this.$prix = prix;
    this.$type = type;
  }

  public get numero(): number {
    return this.$numero;
  }

  public get prix(): number {
    return this.$prix;
  }

  public get type(): string {
    return this.$type;
  }

  public get etage(): number {
    return this.$etage;
  }

  public get nbLits(): number {
    return this.$nbLits;
  }

  public getInfos(): string {
    return this.$type + '[Etage: ' + this.$etage + ' | Nombre Lits: ' + this.$nbLits + ' | Prix/Jour: ' + this.$prix + ']';
  }
}
