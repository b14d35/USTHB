import { Hebergement } from './hebergement.model';

export class Chambre extends Hebergement {

  constructor(etage: number, numero: number, nbLits: number, prix: number) {
    super(etage, numero, nbLits, prix, 'Chambre');
  }
}
