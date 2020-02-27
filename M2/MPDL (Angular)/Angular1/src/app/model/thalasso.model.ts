import { ServicePayant } from './servicePayant.model';

export class Thalasso extends ServicePayant {

  constructor(id: number, prix: number) {
    super(id, prix, 'Thalasso');
  }

}
