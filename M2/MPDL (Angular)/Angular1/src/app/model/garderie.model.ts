import { ServicePayant } from './servicePayant.model';

export class Garderie extends ServicePayant {
  private $nbMaxEnfant: number;

  constructor(id: number, nbMax: number, prix: number) {
    super(id, prix, 'Garderie');
    this.$nbMaxEnfant = nbMax;
  }

  public get nbMaxEnfant(): number {
    return this.$nbMaxEnfant;
  }

  public getInfos(): string {
    return super.getInfos() + ' {Nombre Max d\'enfants: ' + this.$nbMaxEnfant + '}';
  }
}
