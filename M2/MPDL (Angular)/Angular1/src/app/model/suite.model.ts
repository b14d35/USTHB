import { Hebergement } from './hebergement.model';

export class Suite extends Hebergement {
  constructor(etage: number, numero: number, nbLits: number, prix: number) {
    super(etage, numero, nbLits, prix, 'Suite');
  }
}
