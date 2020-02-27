export class Search {
  constructor(
    public page: number,
    public results: {
      adult: boolean,
      poster_path: string,
      overview: string,
      release_date: string,
      genre_ids: number[],
      id: number,
      original_title: string,
      original_language: string,
      title: string,
      backdrop_path: string,
      popularity: number,
      vote_count: number,
      video: boolean,
      vote_average: number
    }[],
    public total_results: number,
    public total_pages: number
  ) { }
}
