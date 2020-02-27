import { ServiceGratuit } from './serviceGratuit.model';

export class Piscine extends ServiceGratuit {
  private $horaireOuverture: number;
  private $horaireFermeture: number;

  constructor(id: number, hOverture: number, hFermeture: number) {
    super(id, 'Piscine');
    this.$horaireOuverture = hOverture;
    this.$horaireFermeture = hFermeture;
  }

  public getInfos(): string {
    return super.getInfos() + ' {Heure Overture: ' + this.$horaireOuverture + ' | Heure Fermeture: ' + this.$horaireOuverture + '}';
  }
}
